#ifndef NODEOFTRIE_H
#define NODEOFTRIE_H

#include <iostream>
#include <vector>

/*!
 * \brief The NodeOfTrieOrPrefixTree struct
 */
struct NodeOfTrieOrPrefixTree
{
    /*!
     * \brief NodeOfTrieOrPrefixTree
     * \param data
     * \param father
     */
    NodeOfTrieOrPrefixTree(char data, NodeOfTrieOrPrefixTree* father):
        data(data), father(father)
    {}

    /*!
     * \brief hasChildOfChar
     * \param c
     * \return
     */
    NodeOfTrieOrPrefixTree* hasChildOfChar(char c)
    {
        NodeOfTrieOrPrefixTree* node = nullptr;
        for (int index = 0; index < vec.size(); ++index)
        {
            node = vec.at(index);
            if (node->data == c)
                return node;
        }
        return nullptr;
    }

    /*!
     * \brief addChild
     * \param node
     */
    void addChild(NodeOfTrieOrPrefixTree* node)
    {
        vec.push_back(node);
    }

    void dealockSubTree()
    {
        for (int index = 0; index < vec.size(); ++index)
        {
            NodeOfTrieOrPrefixTree* node = vec.at(index);
            if (node != nullptr)
            {
                node->dealockSubTree();
                delete node;
            }
        }
    }

    char data = ' ';
    std::vector<NodeOfTrieOrPrefixTree*> vec;
    NodeOfTrieOrPrefixTree* father = nullptr;
    bool isFinal = false;
};

#endif // NODEOFTRIE_H
