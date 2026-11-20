class Solution {
    struct Node {
        int edge = -1, word = -1, pal = -1;
    };
    struct Edge {
        int to, next;
        char letter;
    };
    struct Pal {
        int word, next;
    };
    vector<Node> nodes;
    vector<Edge> edges;
    vector<Pal> pals;
    int child(int node, char letter) {
        for (int edge = nodes[node].edge; edge >= 0; edge = edges[edge].next) if (edges[edge].letter == letter) return edges[edge].to;
        return -1;
    }
    void addPal(int node, int word) {
        pals.push_back( {
            word, nodes[node].pal
        }
        );
        nodes[node].pal = pals.size() - 1;
    }
    vector<char> prefixPalindromes(const string& word) {
        string reversed(word.rbegin(), word.rend());
        string text = word + "#" + reversed;
        vector<int> pi(text.size(), 0);
        for (int i = 1; i < text.size(); i++) {
            int length = pi[i - 1];
            while (length > 0 && text[i] != text[length]) length = pi[length - 1];
            if (text[i] == text[length]) length++;
            pi[i] = length;
        }
        vector<char> result(word.size(), false);
        for (int length = pi.back(); length > 0; length = pi[length - 1]) result[length - 1] = true;
        return result;
    }
    public: vector<vector<int>> palindromePairs(vector<string>& words) {
        nodes.clear();
        edges.clear();
        pals.clear();
        int total = 1;
        for (const string& word : words) total += word.size();
        nodes.reserve(total);
        edges.reserve(total);
        pals.reserve(total + words.size());
        nodes.push_back(Node {
        }
        );
        for (int i = 0; i < words.size(); i++) {
            auto prefix = prefixPalindromes(words[i]);
            int node = 0;
            for (int j = (int)words[i].size() - 1; j >= 0; j--) {
                if (prefix[j]) addPal(node, i);
                int next = child(node, words[i][j]);
                if (next < 0) {
                    next = nodes.size();
                    nodes.push_back(Node {
                    }
                    );
                    edges.push_back( {
                        next, nodes[node].edge, words[i][j]
                    }
                    );
                    nodes[node].edge = edges.size() - 1;
                }
                node = next;
            }
            nodes[node].word = i;
            addPal(node, i);
        }
        vector<vector<int>> result;
        for (int i = 0; i < words.size(); i++) {
            string reversed(words[i].rbegin(), words[i].rend());
            auto suffix = prefixPalindromes(reversed);
            int node = 0, size = words[i].size();
            bool found = true;
            for (int j = 0; j < size; j++) {
                int other = nodes[node].word;
                if (other >= 0 && other != i && suffix[size - j - 1]) result.push_back( {
                    i, other
                }
                );
                node = child(node, words[i][j]);
                if (node < 0) {
                    found = false;
                    break;
                }
            }
            if (found) {
                for (int entry = nodes[node].pal; entry >= 0; entry = pals[entry].next) if (pals[entry].word != i) result.push_back( {
                    i, pals[entry].word
                }
                );
            }
        }
        return result;
    }
};
