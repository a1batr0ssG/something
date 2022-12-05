#include "stdio.h"

void clockWise(int *arr);
void changeDirection(int puz[9][5],int map[9][4]);
void pair(int puz[9][5],int map[9][4]);

void main()
{
	
	//拼图边的对应关系：1-方，2-大圆，3-三角，4-小圆 
	//拼图方向的对应关系：0-上，1-右，2-下，3-左 ，4-顺时针旋转了几次 
	//给地图赋值 
	int map[9][4];
	map[0][3]=1;map[0][0]=4;
	map[1][0]=2;
	map[2][0]=1;map[2][1]=2;
	map[3][3]=3;
	map[5][1]=4;
	map[6][3]=2;map[6][2]=3;
	map[7][2]=4;
	map[8][2]=1;map[8][1]=3;
	
	//给拼图赋值
	int puz[9][5];
	puz[0][0]=2;puz[0][2]=4;puz[0][3]=3;puz[0][1]=2;
	puz[1][0]=2;puz[1][2]=1;puz[1][3]=2;puz[1][1]=3;
	puz[2][0]=2;puz[2][2]=4;puz[2][3]=2;puz[2][1]=2;
	puz[3][0]=2;puz[3][2]=1;puz[3][3]=1;puz[3][1]=3;
	puz[4][0]=2;puz[4][2]=2;puz[4][3]=1;puz[4][1]=1;
	puz[5][0]=2;puz[5][2]=3;puz[5][3]=2;puz[5][1]=3;
	puz[6][0]=4;puz[6][2]=3;puz[6][3]=1;puz[6][1]=4;
	puz[7][0]=4;puz[7][2]=1;puz[7][3]=4;puz[7][1]=1;
	puz[8][0]=4;puz[8][2]=3;puz[8][3]=1;puz[8][1]=2;
	
	changeDirection(puz,map);
} 




void clockWise(int *arr)		//调整每个puz的方向 
{
	int tmp[4];
	tmp[1]=arr[0];
	tmp[2]=arr[1];
	tmp[3]=arr[2];
	tmp[0]=arr[3];
	
	arr[0]=tmp[0];
	arr[1]=tmp[1];
	arr[2]=tmp[2];
	arr[3]=tmp[3];
}

void changeDirection(int puz[9][5],int map[9][4])		//每一个puzzle有四个方向，列出所有方向的可能性 
{
	int a,b,c,d,e,f,g,h,i;
	for(a=0,puz[0][4]=0;a<4;a++){
		if(a!=0){
			clockWise(puz[0]);
			puz[0][4]++;
		}
		for(b=0,puz[1][4]=0;b<4;b++){
			if(b!=0){
				clockWise(puz[1]);
				puz[1][4]++;
			}
			for(c=0,puz[2][4]=0;c<4;c++){
				if(c!=0){
					clockWise(puz[2]);
					puz[2][4]++;
				} 
				for(d=0,puz[3][4]=0;d<4;d++){
					if(d!=0){
						clockWise(puz[3]);
						puz[3][4]++;
					} 
					for(e=0,puz[4][4]=0;e<4;e++){
						if(e!=0){
							clockWise(puz[4]);
							puz[4][4]++;
						}
						for(f=0,puz[5][4]=0;f<4;f++){
							if(f!=0){
								clockWise(puz[5]);
								puz[5][4]++;
							}
							for(g=0,puz[6][4]=0;g<4;g++){
								if(g!=0){
									clockWise(puz[6]);
									puz[6][4]++;
								}
								for(h=0,puz[7][4]=0;h<4;h++){
									if(h!=0){
										clockWise(puz[7]);
										puz[7][4]++;
									}
									for(i=0,puz[8][4]=0;i<4;i++){
										if(i!=0){
											clockWise(puz[8]);
											puz[8][4]++;
										}
										pair(puz,map);
									}
									clockWise(puz[8]);		//再转一次，在下一次大循环开始前将状态归零 
								}
								clockWise(puz[7]);
							}
							clockWise(puz[6]);
						}
						clockWise(puz[5]);
					}
					clockWise(puz[4]);
				}
				clockWise(puz[3]);
			}
			clockWise(puz[2]);
		}
		clockWise(puz[1]);
	}
	clockWise(puz[0]);
}


void pair(int puz[9][5],int map[9][4])		//看puz和map的匹配 
{
	int a,b,c,d,e,f,g,h,i;
	for(a=0;a<9;a++){
		if(map[0][3]!=puz[a][3] || map[0][0]!=puz[a][0])continue;
		for(b=0;b<9;b++){
			if(map[1][0]!=puz[b][0])continue;
			if(puz[b][3]!=puz[a][1])continue;
			if(b==a)continue;
			for(c=0;c<9;c++){
				if(map[2][0]!=puz[c][0] || map[2][1]!=puz[c][1])continue;		//puz和map的边匹配 
				if(puz[c][3]!=puz[b][1])continue;								//puz之间的边匹配 
				if(c==b || c==a)continue;										//同一块puz不能放在两个 map槽里 
				for(d=0;d<9;d++){
					if(map[3][3]!=puz[d][3])continue;
					if(puz[d][0]!=puz[a][2])continue;
					if(d==a || d==b || d==c)continue;
					for(e=0;e<9;e++){
						if(puz[e][3]!=puz[d][1] || puz[e][0]!=puz[b][2])continue;
						if(e==a || e==b || e==c || e==d)continue;
						for(f=0;f<9;f++){
							if(map[5][1]!=puz[f][1])continue;
							if(puz[f][3]!=puz[e][1] || puz[f][0]!=puz[c][2])continue;
							if(f==a || f==b || f==c || f==d || f==e)continue;
							for(g=0;g<9;g++){
								if(map[6][3]!=puz[g][3] || map[6][2]!=puz[g][2])continue;
								if(puz[g][0]!=puz[d][2])continue;
								if(g==a || g==b || g==c || g==d || g==e || g==f)continue;
								for(h=0;h<9;h++){
									if(map[7][2]!=puz[h][2])continue;
									if(puz[h][3]!=puz[g][1] || puz[h][0]!=puz[e][2])continue;
									if(h==a || h==b || h==c || h==d || h==e || h==f || h==g)continue;
									for(i=0;i<9;i++){
										if(map[8][2]!=puz[i][2] || map[8][1]!=puz[i][1])continue;
										if(puz[i][3]!=puz[h][1] || puz[i][0]!=puz[f][2])continue;
										if(i==a || i==b || i==c || i==d || i==e || i==f || i==g || i==h)continue;
										printf("%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次,%d号puz顺时针旋转%d次\n\n",a,puz[a][4],b,puz[b][4],c,puz[c][4],d,puz[d][4],e,puz[e][4],f,puz[f][4],g,puz[g][4],h,puz[h][4],i,puz[i][4]); 
									}
								}
							}
						}
					}
				}
			}
		}
	}
}



