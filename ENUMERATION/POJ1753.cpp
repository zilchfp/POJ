//POJ 1753 Flip Game
/////RESULT : TLE

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;


#define LOCAL

/*
为什么翻过一次的可以不用再翻？
同一个棋局翻白和翻黑的次数是一样的吗？ 


*********关键：某个点翻了两次等于没翻，这些点的选取顺序也不会影响结果！！ 
*/
struct node{
	int visited,step,result;
};




//BLACK = 1 ; WHITE = 0;
int visitedIndex[16] = {32768,16384,8192,4096,
				   2048 , 1024, 512, 256,
				   128  ,   64,  32,  16,
				   8    ,    4,   2,   1 };
int oper[16]={51200,58368,29184,12544,
              35968,20032,10016,4880 ,
			  2248 , 1252, 626 ,305  ,
			  140  ,   78,   39,19    } ;
			  
void dfs(node now,node next){
	
}			  
			  
queue<node> q;
int main(){
#if defined (LOCAL)
    freopen("data.in","r",stdin);
#endif

	unsigned int wei = 32768;
	int input = 0;
	char character;
	while (wei){
		cin >> character ;
		if (character == 'b') {
			input = (unsigned int)input ^ wei;
			wei = wei >> 1;
		}
		else {
			wei = wei >> 1;
		}
	} 

	node begin,now;
	begin.result = input;
	begin.step = 0;
	begin.visited = 0;
	
	q.push(begin); 
	while (!q.empty() ){
		now = q.front() ;
		q.pop() ;
		if (now.result == 0  || now.result == 65535){
			cout << now.step << endl;
			break;
		}
		if (now.visited == 65535) {
			cout << "Impossible" << endl;
			break;
		}
		
		if (now.step >= 4 && (now.result & 0xF000 != 0xF000 )) continue;
		if (now.step >= 8 && (now.result & 0xFF00 != 0XFF00))  continue;
		if (now.step >= 16) continue;
		
		for (int i = 0;i < 16;i++){  
			node next;
			next.result =now.result ^ oper[i];
			next.visited =now.visited | visitedIndex[i];
			next.step = now.step + 1;
			q.push(next);
		}
		
	}	
	return 0;
} 
