#ifndef TRIE_OR_PREFIX_TREE_H
#define TRIE_OR_PREFIX_TREE_H

#include "NodeOfTrieOrPrefixTree.h"

/*!
 * \brief The TrieOrPrefixTreeDS class
 */
class TrieOrPrefixTreeDS
{
public:
    /*!
     * \brief TrieOrPrefixTreeDS
     */
    TrieOrPrefixTreeDS();

    ~TrieOrPrefixTreeDS();

    /*!
     * \brief insert
     * \param word
     */
    void insert(const std::string& word);

    /*!
     * \brief search
     * \param word
     * \return
     */
    NodeOfTrieOrPrefixTree *search(const std::string& word);

    /*!
     * \brief remove
     * \param word
     * \return
     */
    bool remove(const std::string& word);

    /*!
     * \brief getDotFileModeOne
     * \return
     */
    const std::string getDotFileModeOne();

    /*!
     * \brief removeNodeInFather
     * \param childToRemove
     */
    void removeNodeInFather(NodeOfTrieOrPrefixTree *childToRemove);

    /*!
     * \brief getRoot
     * \return
     */
    NodeOfTrieOrPrefixTree * getRoot();

    /*!
     * \brief clearRoot
     */
    void clearRoot();
private:
    struct NodeOfTrieOrPrefixTree* root = nullptr;

    /*!
     * \brief getDotFileModeOne
     * \param node
     * \param textToFile
     */
    void getDotFileModeOne(NodeOfTrieOrPrefixTree *node, std::string& textToFile);
};

#endif // TRIE_OR_PREFIX_TREE_H
