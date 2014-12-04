#include <stdio.h>
#include <stdbool.h>

int table[305];

int SetFind(int x){
    if(table[x] != x) 
    	table[x] = SetFind(table[x]);
    return table[x];
}

void SetUnion(int x, int y){
    x = SetFind(x); 
    y = SetFind(y);
}

int main(){
    int testCases,pointIndex,degree[301],indexI,indexJ;
    
    scanf("%d",&testCases);
    
    while(testCases-- != 0){
        scanf("%d",&pointIndex);
        
        memset(degree,0,sizeof degree);
        int indexX;
        
        while(true){
            scanf("%d %d",&indexI,&indexJ);
            if(indexI == -1 && indexJ == -1) 
            	break;
            ++degree[indexI];
            ++degree[indexJ];
            indexX = indexI;
        }
        
        bool ok = true;
        int i;
        for(i = 1;i <= 300;++i){
            if(degree[i])
                if(degree[i] & 1 || SetFind(i) != SetFind(indexX)) 
                	ok = false;
        }
        
        puts(ok? "YES" : "NO");
    }
    
    return 0;
}
