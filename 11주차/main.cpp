#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

struct nodetype {
  char symbol;
  int frequency;
  nodetype* left;
  nodetype* right;
};
struct cmp {
  bool operator()(nodetype* a, nodetype* b) {
    return a->frequency > b->frequency;
  }
};
typedef priority_queue<nodetype*, vector<nodetype*>, cmp> PQ_nodeptr;

unordered_map<char, int> makeFreq(string const& input) {
  unordered_map<char, int> freq;
  int length = input.size();
  for (int i = 0; i < length; i++) {
    freq[input[i]]++;
  }
  return freq;  // map of frequency
}

PQ_nodeptr makePQ(unordered_map<char, int> const& freq) {
  PQ_nodeptr PQ;
  for (auto v : freq) {
    nodetype* n = new nodetype;
    n->frequency = v.second;
    n->symbol = v.first;
    n->left = nullptr;
    n->right = nullptr;
    PQ.push(n);
  }
  return PQ;
}

nodetype* makeTree(PQ_nodeptr PQ) {
  while (PQ.size() > 1) {
    nodetype* a = PQ.top();
    PQ.pop();
    nodetype* b = PQ.top();
    PQ.pop();
    nodetype* n = new nodetype;
    n->symbol = 0;
    n->frequency = a->frequency + b->frequency;
    n->left = a;
    n->right = b;
    PQ.push(n);
  }
  return PQ.top();  // pointer of root
}

void generateHuffmanCodes(const nodetype* nodeptr, string code,
                          unordered_map<char, string>& codes) {
  if (nodeptr->symbol != 0) codes[nodeptr->symbol] = code;
  if (nodeptr->left) generateHuffmanCodes(nodeptr->left, code + "0", codes);
  if (nodeptr->right) generateHuffmanCodes(nodeptr->right, code + "1", codes);
}

int main() {
  // input string
  const string input_s = "this is test string";
  // string -> freq
  const unordered_map<char, int> freq = makeFreq(input_s);
  // freq -> PQ
  const PQ_nodeptr PQ = makePQ(freq);
  // pq -> tree(root ptr)
  const nodetype* root = makeTree(PQ);

  unordered_map<char, string> codes;
  // tree(root ptr) -> huffman codes
  generateHuffmanCodes(root, "", codes);

  cout << "Huffman code table:\n";
  for (auto v : codes) {
    cout << v.first << ":" << v.second << "\n";
  }

  string encoded_s = "";  // encoded string
  for (int i = 0; i < input_s.size(); i++) {
    encoded_s += codes[input_s[i]];
  }

  cout << "input string: " << input_s << "\n";
  cout << "Encoded string: " << encoded_s << "\n";
}