class Solution {
public:
    typedef pair<int, string> pp;
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        priority_queue<pp, vector<pp>, greater<pp>> genes;

        set<string> allGenes(bank.begin(), bank.end());

        vector<char> changeGene = {'A', 'C', 'G', 'T'};

        genes.push({0, startGene});

        int ans = -1;

        while (not genes.empty()) {
            pair<int, string> curGene = genes.top();
            genes.pop();

            int mutation = curGene.first;
            string gene = curGene.second;

            if (gene == endGene) {
                ans = mutation;
                break;
            }

            for (int i = 0; i < gene.size(); i++) {
                string tempGene = gene;
                for (int j = 0; j < changeGene.size(); j++) {
                    tempGene[i] =  changeGene[j];

                    if (allGenes.count(tempGene)) {
                        allGenes.erase(tempGene);
                        genes.push({mutation + 1,tempGene});
                    }
                }
            }
        }
        return ans;
    }
};