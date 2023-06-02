#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int infocount;
	int info[101];
}node;

node info[101]; // info is store data of graph 
int visit[101]; // visit is using when dfs is work
int vc; // vc is vertex count in dfs

void dfs(int n) { // using bruteforce algorithm 
	for (int i = 0; i < info[n].infocount; i++) {
		if (visit[info[n].info[i]])continue;
		else {
			visit[info[n].info[i]] = 1;
			vc++;
			dfs(info[n].info[i]);
		}
	}
}

int main(void) {
	int v = 0,t1,t2, apcnt = 0; //apcnt is counting articualation point
	scanf("%d", &v);// input number of vertex
	for(int i=0; i<v; i++){
		scanf("%d %d",&t1, &t2);
		info[t1].info[info[t1].infocount++] = t2;
		info[t2].info[info[t2].infocount++] = t1;
	}

	for (int i = 1; i <= v; i++) { // vertex has number that 1 to v(number of vertex)
		for (int j = 1; j <= 100; j++) visit[j] = 0;
		visit[i] = 1;
		vc = 1;
		dfs(info[i].info[0]); // dfs each one
		if (vc < 100)printf("%d ", i); // vc<100 means there is articulation point
	}

	return 0;
}
