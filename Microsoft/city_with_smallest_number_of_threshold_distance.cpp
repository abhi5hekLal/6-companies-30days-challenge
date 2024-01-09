class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));

        for(auto edge: edges) {
            int i = edge[0];
            int j = edge[1];
            int wt = edge[2];

            mat[i][j] = wt;
            mat[j][i] = wt;
        }
        /*
        to reach same node we need zero distance 
        this is necessary becuase initially all 
        the distances are marked as infinity
        */
        for(int i = 0; i < n; i++) mat[i][i] = 0;

        // floyd warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }


        // now iterate over the entire the distance matrix to find the 
        // city with the highest node number and least neighbour
        int node = 100;
        int curMaxNeighbour = 100;

        for(int i = 0; i < n; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(mat[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= curMaxNeighbour) {
                node = i;
                curMaxNeighbour = cnt;
            }
        }

        return node;
        
    }
};