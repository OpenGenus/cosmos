/**
 * @file generic_segment_tree.cpp
 * @author Aryan V S (https://github.com/a-r-r-o-w)
 * @brief Implementation of a Generic Segment Tree
 */

namespace arrow {
    /**
     * @brief Support for two tree memory layouts is provided
     * 
     * Binary:
     *   - creates the segment tree as a full Binary tree
     *   - considering the tree is built over `n` elements, the segment tree would allocate
     *     `4.n` memory for internal usage
     * 
     * EulerTour:
     *   - more memory efficient than Binary segment tree
     *   - considering the tree is build over `n` elements, the segment tree would allocate
     *     `2.n` memory for internal usage
     * 
     * The provided implementation defaults to Binary segment tree if no template parameter is present.
     */
    enum class TreeMemoryLayout {
        Binary,
        EulerTour
    };

    /**
     * @brief Generic Segment Tree
     * 
     * A segment tree allows you to perform operations on an array in an efficient manner
     * 
     * @tparam Type The type of values that the tree holds in its internal nodes
     * @tparam impl_type Memory layout type
     */
    template <
        class Type,
        TreeMemoryLayout impl_type = TreeMemoryLayout::Binary
    >
    class SegmentTree {
    private:
        // Internal members maintained in the segment tree
        std::vector <Type> tree_;
        
        int base_size_;
        const std::vector <Type>& base_ref_;

        Type (*combine_) (const Type&, const Type&);

    public:
        /**
         * @brief Construct a new segment tree object
         * 
         * @param base_size_ Number of leaf nodes segment tree should have (`n` in the tree_memory_layout documentation)
         * @param base Base of the segment tree (leaf node values)
         * @param combine_ Function used to combine_ values of children nodes when building parent nodes
         */
        SegmentTree (int base_size, const std::vector <Type>& base, Type (*combine) (const Type&, const Type&))
            : base_size_ (base_size),
              base_ref_ (base),
              combine_ (combine) {
            if constexpr (impl_type == TreeMemoryLayout::Binary)
                tree_.resize(4 * base_size_, Type{});
            else
                tree_.resize(2 * base_size_, Type{});
            _build_impl(0, 0, base_size_ - 1);
        }

        /**
         * @brief Point update in segment tree. Essentially performs `array[position] = value`.
         * 
         * @param position Index to be updated
         * @param value Value to be set at `position`
         */
        void pointUpdate (int position, const Type& value)
        { _point_update_impl(0, 0, base_size_ - 1, position, value); }

        /**
         * @brief Point query in segment tree. Essentially returns `array[position]`
         * 
         * @param position Index to be queried
         * @return Type `array[position]`
         */
        Type pointQuery (int position)
        { return _point_query_impl(0, 0, base_size_ - 1, position); }

        /**
         * @brief Range query in segment tree. Essentially performs the `combine_` function
         *        on the range `array[l, r]` (bounds are inclusive).
         * 
         * @param l Left bound of query (inclusive)
         * @param r Right bound of query (inclusive)
         * @return Type Result of the query based on `combine_`
         */
        Type rangeQuery (int l, int r)
        { return _range_query_impl(0, 0, base_size_ - 1, l, r); }

        /**
         * @brief Custom point update in segment tree.
         * 
         * The implementation for this method can be added by the user if they would like
         * to perform updates in a different sense from the norm.
         * 
         * @tparam ParamTypes Types of parameters that will be passed to the update implementation
         * @param position Index to be updated
         * @param params Parameter list required by custom update implementation
         */
        template <typename... ParamTypes>
        void customPointUpdate (int position, const ParamTypes&... params)
        { _custom_point_update_impl(0, 0, base_size_ - 1, position, params...); }

        /**
         * @brief Custom point query in segment tree.
         * 
         * The implementation for this method can be added by the user if they would like
         * to perform updates in a different sense from the norm.
         * 
         * @tparam ParamTypes Types of parameters that will be passed to the query implementation
         * @param position Index to be queried
         * @param params Parameter list required by custom query implementation
         */
        template <typename... ParamTypes>
        Type customPointQuery (int position, const ParamTypes&... params)
        { _custom_point_query_impl(0, 0, base_size_ - 1, position, params...); }

        /**
         * @brief Custom query/update in segment tree.
         * 
         * The implementation for this method can be added by the user if they would like
         * to perform queries in a different sense from the norm. It is very flexible with
         * the requirements of the user.
         * 
         * This function is flexible in the sense that you can copy the body multiple times and rename
         * it to achieve different functionality as per liking.
         * 
         * Operations like `lazy propagation` or `beats` or `persistence` have not been implemented, and
         * have been left to the user to do as per their liking. It can be done very easily by manipulating
         * the body of the _custom_query_impl method (and/or creating copies of this function with different
         * names for different purposes).
         * 
         * @tparam ParamTypes Types of parameters that will be passed to the query/update implementation
         * @param params Parameter list required by custom query/update implementation
         */
        template <typename ReturnType, typename... ParamTypes>
        ReturnType customQuery (const ParamTypes&... params)
        { return _custom_query_impl <ReturnType> (0, 0, base_size_ - 1, params...); }

    private:
        /**
         * @brief Returns the index of the left child given the parent index based on
         *        chosen tree_memory_layout
         * 
         * @param v Index of parent
         * @param tl Left bound of parent
         * @param tr Right bound of parent
         * @return int Index of left child of parent
         */
        int _get_leftchild (int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr) {
            if constexpr (impl_type == TreeMemoryLayout::Binary)
                return 2 * v + 1;
            else
                return v + 1;
        }

        /**
         * @brief Returns the index of the right child given the parent index based on
         *        chosen tree_memory_layout
         * 
         * @param v Index of parent
         * @param tl Left bound of parent
         * @param tr Right bound of parent
         * @return int Index of right child of parent
         */
        int _get_rightchild (int v, [[maybe_unused]] int tl, [[maybe_unused]] int tr) {
            if constexpr (impl_type == TreeMemoryLayout::Binary)
                return 2 * v + 2;
            else {
                int tm = (tl + tr) / 2;
                int node_count = tm - tl + 1;
                return v + 2 * node_count;
            }
        }

        /**
         * @brief Internal function to build the segment tree
         * 
         * @param v Index of node where the segment tree starts to build
         * @param tl Left bound of node
         * @param tr Right bound of node
         */
        void _build_impl (int v, int tl, int tr) {
            if (tl == tr) {
                tree_[v] = base_ref_[tl];
                return;
            }

            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);

            _build_impl(lchild, tl, tm);
            _build_impl(rchild, tm + 1, tr);
            
            tree_[v] = combine_(tree_[lchild], tree_[rchild]);
        }

        /**
         * @brief Internal implementation of point_update
         * 
         * @param v Current node index
         * @param tl Current node left bound
         * @param tr Current node right bound
         * @param position Index to be updated
         * @param value Value to be set at `position`
         */
        void _point_update_impl (int v, int tl, int tr, int position, const Type& value) {
            if (tl == tr) {
                tree_[v] = value;
                return;
            }

            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);
            
            // Since we need to only update a single index, we choose the correct
            // "side" of the segment tree to traverse to at each step
            if (position <= tm)
                _point_update_impl(lchild, tl, tm, position, value);
            else
                _point_update_impl(rchild, tm + 1, tr, position, value);
            
            tree_[v] = combine_(tree_[lchild], tree_[rchild]);
        }

        /**
         * @brief Internal implementation of point_query
         * 
         * @param v Current node index
         * @param tl Current node left bound
         * @param tr Current node right bound
         * @param position Index to be updated
         * @return Type Value to be set at `position`
         */
        Type _point_query_impl (int v, int tl, int tr, int position) {
            if (tl == tr)
                return tree_[v];
            
            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);
            
            // Since we need to only update a single index, we choose the correct
            // "side" of the segment tree to traverse to at each step
            if (position <= tm)
                return _point_query_impl(lchild, tl, tm, position);
            else
                return _point_query_impl(rchild, tm + 1, tr, position);
        }

        /**
         * @brief Internal implementation of rangeQuery
         * 
         * @param v Current node index
         * @param tl Current node left bound
         * @param tr Current node right bound
         * @param l Current query left bound
         * @param r Current query right bound
         * @return Type Result of the query
         */
        Type _range_query_impl (int v, int tl, int tr, int l, int r) {
            // We are out of bounds in our search
            // Return a sentinel value which must be defaulted in the constuctor of Type
            if (l > r)
                return {};
            
            // We have found the correct range for the query
            // Return the value at current node because it's not required to process further
            if (tl == l and tr == r)
                return tree_[v];
            
            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);

            // We have not yet found the correct range for the query
            // Get results of left child and right child and combine_
            Type lval = _range_query_impl(lchild, tl, tm, l, std::min(r, tm));
            Type rval = _range_query_impl(rchild, tm + 1, tr, std::max(l, tm + 1), r);
            
            return combine_(lval, rval);
        }

        /**
         * @brief Internal implementation of customPointUpdate
         * 
         * Note that you need to change the definition of this function if you're passing
         * any variadic argument list in customPointUpdate
         * 
         * @param v Current node index
         * @param tl Current node left bound
         * @param tr Current node right bound
         * @param position Index to be updated
         */
        void _custom_point_update_impl (int v, int tl, int tr, int position) {
            if (tl == tr) {
                throw std::runtime_error("undefined implementation");
                return;
            }

            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);

            // Since we need to only update a single index, we choose the correct
            // "side" of the segment tree to traverse to at each step
            if (position <= tm)
                _custom_point_update_impl(lchild, tl, tm, position);
            else
                _custom_point_update_impl(rchild, tm + 1, tr, position);
            
            tree_[v] = combine_(tree_[lchild], tree_[rchild]);
        }

        /**
         * @brief Internal implementation of customPointQuery
         * 
         * Note that you need to change the definition of this function if you're passing
         * any variadic argument list in customPointQuery
         * 
         * @param v Current node index
         * @param tl Current node left bound
         * @param tr Current node right bound
         * @param position Index to be queried
         * @return Type Result of the query
         */
        Type _custom_point_query_impl (int v, int tl, int tr, int position) {
            if (tl == tr) {
                throw std::runtime_error("undefined implementation");
                return {};
            }

            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);

            // Since we need to only update a single index, we choose the correct
            // "side" of the segment tree to traverse to at each step
            if (position <= tm)
                return _custom_point_query_impl(lchild, tl, tm, position);
            else
                return _custom_point_query_impl(rchild, tm + 1, tr, position);
        }

        /**
         * @brief Internal implementation of customQuery
         * 
         * The user can create multiple copies with different names for this function and make
         * calls accordingly. Read the documentation for customQuery above.
         * 
         * @tparam ReturnType Return type of the custom query/update
         * @param v Current node index
         * @param tl Current node left bound
         * @param tr Current node right bound
         * @return ReturnType Return value of the custom query/update
         */
        template <typename ReturnType>
        ReturnType _custom_query_impl (int v, int tl, int tr) {
            if (tl == tr) {
                throw std::runtime_error("undefined implementation");
                return ReturnType{};
            }
            
            int tm = (tl + tr) / 2;
            int lchild = _get_leftchild(v, tl, tr);
            int rchild = _get_rightchild(v, tl, tr);

            // Change functionality as per liking
            if (true)
                return _custom_query_impl <ReturnType> (lchild, tl, tm);
            else
                return _custom_query_impl <ReturnType> (rchild, tm + 1, tr);
        }
    };
};
