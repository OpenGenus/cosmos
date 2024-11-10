"""
Created on Mon Oct 22 2018

@author: Po-Chun, Lu
"""
import logging

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(name)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)
logger.setLevel(level=logging.INFO)

class FPTree:
    def __init__(self):
        self.counts = 1
        self.children = None

    def insert_node(self, item):
        if self.children == None:
            self.children = {}
            self.children[item] = FPTree()
        elif item not in self.children:
            self.children[item] = FPTree()
        else:
            self.children[item].counts += 1


class FPGrowth:
    def __init__(self, input_data, minsup):
        self.item_counts = self._count_min_items(input_data, minsup)
        self.sorted_data = self._convert_data(input_data)
        self.sorted_items = self._get_sorted_items(self.item_counts)
        self.fp_tree = self._build_FPTree(self.sorted_data)
        # final results: Frequent Patterns
        self.fp_dict = self._find_fp(minsup)

    #
    # Part 1: Basic Process
    #
    def _count_items(self, input_data):
        item_counts = {}
        for data in input_data:
            for item in data:
                if item not in item_counts:
                    item_counts[item] = 1
                else:
                    item_counts[item] += 1
        return item_counts

    # filter items which counts small than minsup
    def _count_min_items(self, input_data, minsup):
        item_counts = self._count_items(input_data)
        return {key: value for key, value in item_counts.items() if value >= minsup}

    def _sort_transaction(self, transaction, reverse=True):
        def sortByCounts(item):
            return self.item_counts[item]

        transaction.sort(key=sortByCounts, reverse=reverse)
        return transaction

    def _convert_transaction(self, transaction):
        # filter items which counts small than minsup
        filtered_transaction = [item for item in transaction if item in self.item_counts]
        # sort desceding
        sorted_transaction = self._sort_transaction(filtered_transaction)
        return sorted_transaction

    def _convert_data(self, input_data):
        return list(map(self._convert_transaction, input_data))

    def _get_sorted_items(self, item_counts):
        return self._sort_transaction(list(item_counts.keys()), False)

    def _build_FPTree(self, data_list):
        Root = FPTree()
        current_node = Root
        for transaction in data_list:
            # When combining suffix patterns, input type is string
            if isinstance(transaction, str):
                transaction = transaction.split(',')

            for item in transaction:
                current_node.insert_node(item)
                current_node = current_node.children[item]
            current_node = Root

        return Root

    #
    # Part 2: Frequent Patterns
    #
    def _find_fp(self, minsup):
        def find_suffix_patterns(item, current_node, storage):
            for node_name in current_node.children:
                next_node = current_node.children[node_name]
                # When finding key pattern, log its path
                if node_name == item:
                    for i in range(next_node.counts):
                        storage['suffix_patterns'].append(','.join(storage['path_list']))
                elif next_node.children != None:
                    storage['path_list'].append(node_name)
                    find_suffix_patterns(item, next_node, storage)

            if storage['path_list']:
                storage['path_list'].pop()


        def find_single_fp(item, current_node, path_list, fp_dict):
            if current_node.children != None:
                for node_name in current_node.children:
                    next_node = current_node.children[node_name]
                    path_list.append(node_name)
                    current_path = '-'.join(path_list)

                    if len(path_list) > 1:
                        full_path = node_name + '-' + item
                        if full_path not in fp_dict:
                            fp_dict[full_path] = next_node.counts
                        else:
                            fp_dict[full_path] += next_node.counts

                    if len(current_path) > 0:
                        full_path = current_path + '-' + item
                        if full_path not in fp_dict:
                            fp_dict[full_path] = next_node.counts
                        else:
                            fp_dict[full_path] += next_node.counts

                    find_single_fp(item, next_node, path_list, fp_dict)
                if path_list:
                    path_list.pop()
            else:
                path_list.pop()

        # start find patterns
        fp_dict = {}
        for item in self.sorted_items:
            # find suffix patterns
            storage = {
                'suffix_patterns': [],
                'path_list': [],
            }
            find_suffix_patterns(item, self.fp_tree, storage)
            # pattern combination
            combined_pattern = self._build_FPTree(storage['suffix_patterns'])
            find_single_fp(item, combined_pattern, [], fp_dict)

        # add single item counts
        for key in self.item_counts:
            fp_dict[key] = self.item_counts[key]

        # remove patterns that counts < minsup
        pop_list = []
        for key in fp_dict:
            if fp_dict[key] < minsup:
               pop_list.append(key)

        for key in pop_list:
            fp_dict.pop(key, 'None')

        logger.info(fp_dict)
        return fp_dict

def str_to_list(input_data):
    data_list = [
        data.replace(',\n', '').split(',')
        for data in input_data
    ]
    return data_list


if __name__ == '__main__':
    import argparse
    parser = argparse.ArgumentParser()
    parser.add_argument('--input',
                       default='./data/sample.txt',
                       help='input data file name')
    parser.add_argument('--output',
                        default='output.csv',
                        help='output file name')
    parser.add_argument('--minsup',
                       default=0.3,
                       help='input minsup')

    args = parser.parse_args()

    with open('./data/sample.txt', 'r') as input_file, open(args.output, 'w') as output:

        data_list = str_to_list(input_file)

        minsup = int( float(args.minsup) * len(data_list) )
        fp_results = FPGrowth(data_list, minsup)

        output.write('pattern,counts\n')
        for key in fp_results.fp_dict:
            output.write(str(key) + ',' + str(fp_results.fp_dict[key]))
            output.write('\n')

        print('finish')

