#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
vector<vector<string>> tk;
bool check[10001];
bool isans;
void dfs(string start, int cnt)
{
    ans.push_back(start);
    if (cnt == tk.size())
        isans = true;
    for (int i = 0;i < tk.size();i++)
    {
        if (check[i])
            continue;
        if (tk[i][0] == start)
        {
            check[i] = true;
            dfs(tk[i][1], ++cnt);
            if (!isans)
            {
                ans.pop_back();
                check[i] = false;
            }

        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    string cur = "ICN";
    sort(tickets.begin(), tickets.end());
    tk = tickets;
    dfs("ICN", 0);
    return ans;
}

int main()
{
    solution({ {"ICN","JFK"},{"HND","IAD"},{"JFK","HND"} });
    return 0;
}