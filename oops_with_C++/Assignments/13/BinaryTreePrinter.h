/**
 * Printer for a binary tree of up to height 5.
 *
 * Author: Ron Mak
 *         Department of Computer Engineering
 *         San Jose State University
 */
#ifndef BINARY_TREE_PRINTER_H
#define BINARY_TREE_PRINTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "BinaryNode.h"
#include "BinarySearchTree.h"

class BinaryTreePrinter
{
public:
    static const int MAX_HEIGHT = 5;  // cannot print trees > MAX_HEIGHT

private:
    static const int MAX_LEVELS = MAX_HEIGHT + 1;
    static const int POWERS_OF_2[];

public:
    /**
     * Constructor.
     * @param tree the tree to print.
     */
    BinaryTreePrinter(BinarySearchTree& tree);

    /**
     * Destructor.
     */
    virtual ~BinaryTreePrinter();

    /**
     * Print the tree using a level-order traversal.
     */
    void print();

private:
    BinarySearchTree& tree;  // the tree to print

    /**
     * Print node data.
     * @param level the current level
     * @param offset the current offset
     * @param levelNodes the current level of nodes
     */
    void print_data(int level, int offset,
                    BinaryNode *levelNodes[]);

    /**
     * Print outgoing pointers /\ from each non-null parent node->
     * @param level the current level
     * @param offset the current offset
     * @param levelNodes the current level of nodes
     */
    void print_outgoing_pointers(int level, int offset,
                                 BinaryNode *levelNodes[]);

    /**
     * Print the connecting dashes between
     * an outgoing pointer and an incoming pointer.
     * @param level the current level
     * @param offset the current offset
     * @param levelNodes the current level of nodes
     */
    void print_connecting_dashes(int level, int offset,
                                 BinaryNode *levelNodes[]);

    /**
     * Print incoming pointers / or \ to each non-null child node->
     * @param level the current level
     * @param offset the current offset
     * @param levelNodes the current level of nodes
     */
    void print_incoming_pointers(int level, int offset,
                                 BinaryNode *levelNodes[]);

    /**
     * Prepare the next level of nodes.
     * @param level the current level
     * @param levelNodes the current level of nodes
     * @return the next level of nodes.
     */
    void prepare_next_level(int level, BinaryNode *levelNodes[]);

    /**
     * Print spaces.
     * @param count the number of spaces.
     */
    void print_spaces(int count);

    /**
     * Print dashes.
     * @param count the number of dashes.
     */
    void print_dashes(int count);
};

#endif // BINARY_TREE_PRINTER_H