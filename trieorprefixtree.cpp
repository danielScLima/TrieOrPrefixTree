#include "trieorprefixtree.h"
#include <iostream>
#include <queue>

#include <sstream> //for std::stringstream
#include <string>  //for std::string

TrieOrPrefixTree::TrieOrPrefixTree()
{
    //The root element must be keept
    this->root = new NodeOfTrieOrPrefixTree(' ', nullptr);
}

TrieOrPrefixTree::~TrieOrPrefixTree()
{
    if (this->root != nullptr)
    {
        this->root->dealockSubTree();
        delete this->root;
    }
}

void TrieOrPrefixTree::insert(const std::string& word)
{
    NodeOfTrieOrPrefixTree* tmp = root;
    for (int index = 0; index < word.size(); ++index)
    {
        NodeOfTrieOrPrefixTree* cont = tmp->hasChildOfChar(word[index]);
        if (cont != nullptr) //já existe
        {
            tmp = cont; //se tornou o cara da iteração index
        }
        else
        {
            NodeOfTrieOrPrefixTree* cont = new NodeOfTrieOrPrefixTree(word[index], tmp);
            tmp->addChild(cont);
            tmp = cont; //se tornou o cara da iteração index
        }

        if (index == word.size() - 1) //the last one
            tmp->isFinal = true;
    }

}

NodeOfTrieOrPrefixTree* TrieOrPrefixTree::search(const std::string& word)
{
    NodeOfTrieOrPrefixTree* tmp = root;
    for (int index = 0; index < word.size(); ++index)
    {
        NodeOfTrieOrPrefixTree* cont = tmp->hasChildOfChar(word[index]);
        if (cont != nullptr) //já existe
        {
            tmp = cont; //se tornou o cara da iteração index
        }
        else
        {
            return nullptr; //não tem essa palavra
        }

        if (index == word.size() - 1) //the last one
        {
            if (tmp->isFinal == false)
                return nullptr; //só tem o prefixo
        }
    }

    return tmp; //retorna o ponteiro para o último nó
}

bool TrieOrPrefixTree::remove(const std::string& word)
{
    NodeOfTrieOrPrefixTree* finalNode = TrieOrPrefixTree::search(word);
    if (finalNode == nullptr)
        return false;

    //tira a indicação de final
    finalNode->isFinal = false;

    NodeOfTrieOrPrefixTree* tmp = finalNode;
    NodeOfTrieOrPrefixTree* backupTmp = nullptr;

    //Verificar se pode remover o nó final
    while (tmp->vec.size() == 0 &&
           (tmp->isFinal == false) &&
           tmp != root) //não tem outro alem
    {
        removeNodeInFather(tmp);
        backupTmp = tmp;
        tmp = tmp->father;
        delete backupTmp;
    }

    return true;
}

void TrieOrPrefixTree::removeNodeInFather(NodeOfTrieOrPrefixTree* childToRemove)
{
    NodeOfTrieOrPrefixTree* father = childToRemove->father;
    for (int index = 0; index < father->vec.size(); ++index)
    {
        if (father->vec.at(index) == childToRemove)
        {
            //remove o nó de index: index
            father->vec.erase(father->vec.begin()+index);
            break;
        }
    }
}

NodeOfTrieOrPrefixTree *TrieOrPrefixTree::getRoot()
{
    return this->root;
}

const std::string TrieOrPrefixTree::getDotFileModeOne()
{
    std::string textToFile = "digraph g{";

    if (root == nullptr)
    {
        textToFile += "NULL;Root [shape=record]; Root -> NULL;";
    }
    else
    {
        textToFile += "Root [shape=record]; rootwithnothing [label=\" \"]; Root -> rootwithnothing;";

        if (root->vec.size() > 0)
            getDotFileModeOne(root, textToFile);
    }

    textToFile += "}";

    return textToFile;
}


std::string getPointerAsString(NodeOfTrieOrPrefixTree* node)
{
    const void * address = static_cast<const void*>(node);
    std::stringstream ss;
    ss << address;
    std::string name = ss.str();
    return "\""+name+"\"";
}

std::string getNodeRepresentation(NodeOfTrieOrPrefixTree* node)
{
    std::string ret = getPointerAsString(node);
    ret += getPointerAsString(node) +"[ label= \""+std::string(1, node->data)+"\" ";

    //Inserir outras propriedades
    if (node->isFinal)
    {
        ret += "color=red fontcolor=white style=filled";
    }

    ret += "];";
    return ret;
}

void TrieOrPrefixTree::getDotFileModeOne(NodeOfTrieOrPrefixTree* node, std::string& textToFile)
{
    if (node != root)
        textToFile += getNodeRepresentation(node);

    for (auto n: node->vec)
    {
        if (node != root)
        {
            textToFile += getPointerAsString(node) + " -> " +
                    getPointerAsString(n) + ";";
        }
        else
        {
            textToFile += "rootwithnothing -> " +
                    getPointerAsString(n) + ";";
        }
        getDotFileModeOne(n, textToFile);
    }
}
