class Solution {
public:
    int dx[4]= {-1,0,1,0};
    int dy[4]= {0,1,0,-1};
    void floodfill(vector<vector<int>>& image,int i,int j,int ch,int newColor)
    {
        int R = image.size();
        int C = image[0].size();
        
        //base
        if(i<0||j<0||i>=R||j>=C)
        {
            return;
        }
        
        //Boundary
        if(image[i][j]!=ch||image[i][j]==newColor)
        {
            return;
        }
        
        //Recusive call
        image[i][j]=newColor;
        for(int k=0;k<4;k++)
        {
            floodfill(image,i+dx[k],j+dy[k],ch,newColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        int ch = image[sr][sc];
        
        floodfill(image,sr,sc,ch,newColor);
        
        return image;
        
    }
};