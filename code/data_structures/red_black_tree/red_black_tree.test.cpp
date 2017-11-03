#include "red_black_tree.cpp"

void
test() {
    std::shared_ptr<RBTree<int> > rbt;
    rbt = make_shared<RBTree<int> >();
    rbt->find(3);
    assert(rbt->preOrder() == "");
    assert(rbt->find(32) == nullptr);
    rbt->insert(1);
    rbt->insert(4);
    rbt->insert(7);
    rbt->insert(10);
    rbt->insert(2);
    rbt->insert(6);
    rbt->insert(8);
    rbt->insert(3);
    rbt->insert(5);
    rbt->insert(9);
    rbt->insert(100);
    assert(rbt->preOrder() == "74213659810100");
    rbt->insert(40);
    assert(rbt->preOrder() == "7421365984010100");
    rbt->insert(30);
    assert(rbt->preOrder() == "742136598401030100");
    rbt->insert(20);
    assert(rbt->preOrder() == "74213659840201030100");
    rbt->insert(15);
    assert(rbt->preOrder() == "7421365209810154030100");
    rbt->insert(50);
    assert(rbt->preOrder() == "742136520981015403010050");
    rbt->insert(60);
    assert(rbt->preOrder() == "74213652098101540306050100");
    rbt->insert(70);
    assert(rbt->preOrder() == "7421365209810154030605010070");
    rbt->insert(80);
    assert(rbt->preOrder() == "742136520981015403060508070100");
    rbt->insert(63);
    assert(rbt->preOrder() == "74213652098101560403050807063100");
    rbt->insert(67);
    assert(rbt->preOrder() == "7421365209810156040305080676370100");
    rbt->insert(65);
    rbt->insert(69);
    rbt->insert(37);
    rbt->insert(33);
    rbt->insert(35);
    rbt->insert(31);
    assert(rbt->inOrder() == "1234567891015203031333537405060636567697080100");
    assert(rbt->preOrder() == "2074213659810156040333031373550806763657069100");
    assert(rbt->find(31) != nullptr);
    assert(rbt->find(32) == nullptr);
    
    rbt->erase(69);
    assert(rbt->preOrder() == "20742136598101560403330313735508067636570100");
    rbt->erase(65);
    assert(rbt->preOrder() == "207421365981015604033303137355080676370100");
    rbt->erase(1);
    assert(rbt->preOrder() == "20742365981015604033303137355080676370100");
    rbt->erase(3);
    assert(rbt->preOrder() == "2074265981015604033303137355080676370100");
    rbt->erase(2);
    assert(rbt->preOrder() == "207546981015604033303137355080676370100");
    rbt->erase(60);
    assert(rbt->preOrder() == "2075469810155033303137354080676370100");
    rbt->erase(35);
    assert(rbt->preOrder() == "20754698101550333031374080676370100");
    rbt->erase(37);
    assert(rbt->preOrder() == "207546981015503330314080676370100");
    rbt->erase(40);
    assert(rbt->preOrder() == "2075469810155031303380676370100");
    rbt->erase(50);
    assert(rbt->preOrder() == "20754698101567333130638070100");
    rbt->erase(20);
    assert(rbt->preOrder() == "157546981067333130638070100");
    rbt->erase(15);
    assert(rbt->preOrder() == "1075469867333130638070100");
    rbt->erase(10);
    assert(rbt->preOrder() == "97546867333130638070100");
    rbt->erase(9);
    assert(rbt->preOrder() == "8547667333130638070100");
    rbt->erase(100);
    assert(rbt->preOrder() == "8547667333130638070");
    rbt->erase(70);
    assert(rbt->preOrder() == "85476673331306380");
    rbt->erase(80);
    assert(rbt->preOrder() == "854763331306763");
}

// test of RBTree methods
struct RBTreeTest
{
    typedef RBTree<int> tree_type;
    using node_type = tree_type::node_type;
    using p_node_type = tree_type::p_node_type;
    using Color = tree_type::Color;
    
    RBTreeTest() {
        testSibling();
        
        // below test of delete cases need ignore invoke
        testDeleteCase2();
        testDeleteCase3();
        testDeleteCase4();
        testDeleteCase5();
        testDeleteCase6();
    }
    
    void testSibling() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), l = std::make_shared<node_type>(0),
        r = std::make_shared<node_type>(0);
        n->left = l;
        n->right = r;
        l->parent = n;
        r->parent = n;
        assert(t.sibling(l) == r);
        assert(t.sibling(r) == l);
    }
    
    void testDeleteCase2() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
        s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
        sr = std::make_shared<node_type>(0);
        
        // test n is left of parent
        p->color = Color::BLACK;
        s->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase2(n);
        assert(p->color == Color::RED);
        assert(s->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sl->left == t.sentinel_);
        assert(sl->right == t.sentinel_);
        assert(sr->left == t.sentinel_);
        assert(sr->right == t.sentinel_);
        assert(s->left == p);
        assert(s->right == sr);
        assert(p->parent == s);
        assert(sr->parent == s);
        assert(p->left == n);
        assert(p->right == sl);
        assert(n->parent == p);
        assert(sl->parent == p);
        
        // test n is right of parent
        p->color = Color::BLACK;
        s->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase2(n);
        assert(p->color == Color::RED);
        assert(s->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sl->left == t.sentinel_);
        assert(sl->right == t.sentinel_);
        assert(sr->left == t.sentinel_);
        assert(sr->right == t.sentinel_);
        assert(s->left == sl);
        assert(s->right == p);
        assert(sl->parent == s);
        assert(p->parent == s);
        assert(p->left == sr);
        assert(p->right == n);
        assert(sr->parent == p);
        assert(n->parent == p);
    }
    
    void testDeleteCase3() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
        s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
        sr = std::make_shared<node_type>(0);
        n->color = p->color = s->color = sl->color = sr->color = Color::BLACK;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase3(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
        
        n->color = p->color = s->color = sl->color = sr->color = Color::BLACK;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase3(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
    }
    
    void testDeleteCase4() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
        s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
        sr = std::make_shared<node_type>(0);
        n->color = s->color = sl->color = sr->color = Color::BLACK;
        p->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase4(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
        
        n->color = s->color = sl->color = sr->color = Color::BLACK;
        p->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = sr->left = sr->right = t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        t.deleteCase4(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
    }
    
    void testDeleteCase5() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
        s = std::make_shared<node_type>(0), sl = std::make_shared<node_type>(0),
        sr = std::make_shared<node_type>(0), s_l = std::make_shared<node_type>(0),
        s_r = std::make_shared<node_type>(0);
        n->color = p->color = s->color = sr->color = s_l->color = s_r->color = Color::BLACK;
        sl->color = Color::RED;
        p->parent = n->left = n->right = sr->left = sr->right = \
        s_l->left = s_l->right = s_r->left =
        s_r->right =
        t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        sl->left = s_l;
        sl->right = s_r;
        s_l->parent = s_r->parent = sl;
        t.deleteCase5(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
        assert(s_l->color == Color::BLACK);
        assert(s_r->color == Color::BLACK);
        assert(p->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sr->left == t.sentinel_);
        assert(sr->right == t.sentinel_);
        assert(s_l->left == t.sentinel_);
        assert(s_l->right == t.sentinel_);
        assert(s_r->left == t.sentinel_);
        assert(s_r->right == t.sentinel_);
        assert(p->left == n);
        assert(p->right == sl);
        assert(n->parent == p);
        assert(sl->parent == p);
        assert(sl->left == s_l);
        assert(sl->right == s);
        assert(s_l->parent == sl);
        assert(s->parent == sl);
        assert(s->left == s_r);
        assert(s->right == sr);
        assert(s_r->parent == s);
        assert(sr->parent == s);
        
        n->color = p->color = s->color = sl->color = s_l->color = s_r->color = Color::BLACK;
        sr->color = Color::RED;
        p->parent = n->left = n->right = sl->left = sl->right = \
        s_l->left = s_l->right = s_r->left =
        s_r->right =
        t.sentinel_;
        p->left = s;
        p->right = n;
        n->parent = s->parent = p;
        s->left = sl;
        s->right = sr;
        sl->parent = sr->parent = s;
        sr->left = s_l;
        sr->right = s_r;
        s_l->parent = s_r->parent = sr;
        t.deleteCase5(n);
        assert(s->color == Color::RED);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(sl->color == Color::BLACK);
        assert(sr->color == Color::BLACK);
        assert(s_l->color == Color::BLACK);
        assert(s_r->color == Color::BLACK);
        assert(p->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(sl->left == t.sentinel_);
        assert(sl->right == t.sentinel_);
        assert(s_l->left == t.sentinel_);
        assert(s_l->right == t.sentinel_);
        assert(s_r->left == t.sentinel_);
        assert(s_r->right == t.sentinel_);
        assert(p->left == sr);
        assert(p->right == n);
        assert(n->parent == p);
        assert(sr->parent == p);
        assert(sr->left == s);
        assert(sr->right == s_r);
        assert(s->parent == sr);
        assert(s_r->parent == sr);
        assert(s->left == sl);
        assert(s->right == s_l);
        assert(sl->parent == s);
        assert(s_l->parent == s);
    }
    
    void testDeleteCase6() {
        tree_type t;
        p_node_type n = std::make_shared<node_type>(0), p = std::make_shared<node_type>(0),
        s = std::make_shared<node_type>(0), sc = std::make_shared<node_type>(0);
        p->color = n->color = s->color = Color::BLACK;
        sc->color = Color::RED;
        p->parent = n->left = n->right = s->left = sc->left = sc->right = t.sentinel_;
        p->left = n;
        p->right = s;
        n->parent = p;
        s->parent = p;
        s->right = sc;
        sc->parent = s;
        t.deleteCase6(n);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(s->color == Color::BLACK);
        assert(sc->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(p->right == t.sentinel_);
        assert(sc->left == t.sentinel_);
        assert(sc->right == t.sentinel_);
        assert(s->left == p);
        assert(s->right == sc);
        assert(p->parent == s);
        assert(sc->parent == s);
        assert(p->left == n);
        assert(n->parent == p);
        
        p->color = n->color = s->color = Color::BLACK;
        sc->color = Color::RED;
        p->parent = n->left = n->right = s->right = sc->left = sc->right = t.sentinel_;
        p->left = s;
        p->right = n;
        s->parent = p;
        n->parent = p;
        s->left = sc;
        sc->parent = s;
        t.deleteCase6(n);
        assert(p->color == Color::BLACK);
        assert(n->color == Color::BLACK);
        assert(s->color == Color::BLACK);
        assert(sc->color == Color::BLACK);
        assert(s->parent == t.sentinel_);
        assert(n->left == t.sentinel_);
        assert(n->right == t.sentinel_);
        assert(p->left == t.sentinel_);
        assert(sc->left == t.sentinel_);
        assert(sc->right == t.sentinel_);
        assert(s->left == sc);
        assert(s->right == p);
        assert(sc->parent == s);
        assert(p->parent == s);
        assert(p->right == n);
        assert(n->parent == p);
    }
};

// Driver Code
int
main()
{
    RBTreeTest t;
    test();
    
    return 0;
}