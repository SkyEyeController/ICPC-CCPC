#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> nexts;
vector<nexts> connects[300001];
priority_queue<nexts, vector<nexts>, greater<nexts>> qfirst, qothers;
// qfirst的含义是在第i-1天的感染者辐射下的密接圈内的人，qothers含义是指在第i-1天感染者辐射下次密接及次次密接
// 等非密接但是能被感染距离污染的人
int dist[300001], infectdays[300001];
int n, m, k, d;
void cin_graph(int &n, int &m) // 全部初始化
{
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        connects[u].push_back(nexts(v /*pos*/, w /*w*/));
        connects[v].push_back(nexts(u, w));
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 2147483647;
        infectdays[i] = -1;
    }
    return;
}
int main()
{
    cin_graph(n, m);
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int location; // 初始感染者坐标；
        cin >> location;
        dist[location] = 0;
        infectdays[location] = 0;
        for (int j = 0; j < connects[location].size(); j++)
        {
            int u = connects[location][j].first;
            int w = connects[location][j].second;
            if (dist[u] > dist[location] + w)
            {
                dist[u] = dist[location] + w;   // 第i-1天的感染者在第i天可能的密接圈路径
                qfirst.push(nexts(dist[u], u)); // 单对起点，由于第i-1天的感染者并不唯一，所以存入临时密接圈
                // 的dist数值只是说明当前location下的距离而非最短距离（可能两个点能够同时到一个点但距离不一）
                // ，但是一直在全局的dist数组却是能保证第i-1天感染者组成的集合针对其他密接圈内人的最短距离
            }
        }
    }
    cin >> d;
    for (int i = 1; i <= d; i++) // 彻底转变思路，以病毒爆发第i天来进行规划。
    // 病毒爆发的第i天，由第i-1天及以前的所有人组成的集合向外辐射最大距离为Di的病毒污染人群。而污染分成了两大类情况。
    /*1.感染者距离不够感染任何人（感染距离小于密接圈最短距离）。
      2.感染者距离恰好能够感染密接圈内的某人(密接圈外距离够不到）。
      3.感染者距离能够辐射到密接圈之外的人。
      如果单纯以密接圈内所有人为基准进行最短路径规划会有非常恐怖的时间复杂度（大约是n^2,这还是不计算队列优化的
      Dijkstra的nlogn的前提下，面对3e5的数据绝对超时，所以我们优化计算的时候，仅对可能辐射到次密接的部分进行
      Dijkstra_queue计算，减少大面积的无必要的计算。
    */
    {
        int ability;
        cin >> ability; // 第i天的最大感染辐射范围。
        vector<nexts> infectedperson;
        while (!qfirst.empty())
        {
            nexts node = qfirst.top();
            qfirst.pop();
            int dis = node.first, location = node.second;
            if (dis > dist[location])
                continue; // 这就是涉及到上文注释过的点集合到目标位置的最短距离筛选，只有两者
            // 相等的时候才是最短距离，符合题目要求。
            if (ability < dis)
            {
                qfirst.push(node);
                break;
            } // 1.密接圈内该人不能被感染，此时由于优先队列特性，node后面所有的节点都不可能被感染，所以直接打破
              // 密接圈排查，密接圈内剩余人将在第二天继续排查。
              /*
              这里同时涉及到了一个greater<pair<int,int>>的特性，该函数的含义如下：
              template<typename T> struct greater
              {
                  constexpr bool operator()(T const& a, T const& b) const
                  {
                      return a.first>b.first || ( (a.first<b.first) && (a.second>b.second));
                  }
               };
              */
            qothers.push(nexts(dis, location));
        }
        while (!qothers.empty())
        {
            nexts node = qothers.top();
            qothers.pop();
            int dis = node.first, location = node.second;
            if (dis > dist[location])
                continue; // 同理，多源起点取最短距离必须有部分。
            infectedperson.push_back(node);
            for (int j = 0; j < connects[location].size(); j++) // 既然目标人已经进入感染的辐射范围，
            // 那么探查其是否可能存在辐射到次密接的可能性，进行最短路径。
            {
                int v = connects[location][j].first;
                int w = connects[location][j].second;
                if (dist[v] > dist[location] + w)
                {
                    dist[v] = dist[location] + w;
                    if (dist[v] <= ability) // 从该路径仍存在继续辐射的可能性
                        qothers.push(nexts(dist[v], v));
                }
            }
        } // qothers变为空的时候，infectperson即保存了全部在第i天被感染的人。
        for (int j = 0; j < infectedperson.size(); j++)
        {
            int location = infectedperson[j].second;
            infectdays[location] = i;
            dist[location] = 0; // 作为第i批被感染的人去初始化感染第i+1天的人。
            for (int p = 0; p < connects[location].size(); p++)
            {
                int u = connects[location][p].first;
                int w = connects[location][p].second;
                if (dist[u] > dist[location] + w)
                {
                    dist[u] = dist[location] + w;
                    qfirst.push(nexts(dist[u], u));
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << infectdays[i] << endl;
    system("pause");
    return 0;
}