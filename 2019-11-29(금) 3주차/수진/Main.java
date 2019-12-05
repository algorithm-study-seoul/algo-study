package ¼û¹Ù²ÀÁú;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	static int N,K;
	static int count=0;
	static Queue<Integer> q=new LinkedList<Integer>();
	static int[] v;

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		v=new int[100002];
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		N=Integer.parseInt(st.nextToken());
		K=Integer.parseInt(st.nextToken());
			
		q.add(N);
		v[N]=1;
		
		bfs();
		
//		int ans=0;
//		while(count>1) {
//			count/=3;
//			ans++;
//		}
		System.out.println(v[K]-1);
	}

	private static void bfs() {
		
		

		while(!q.isEmpty()) {
			//count++;

			int num=q.poll();
			if(num==K) break;
			
			for(int i=0;i<3;i++) {
				int tmp=0;
				switch(i) {
					case 0:
						tmp=num+1;
						break;
					case 1:
						tmp=num-1;
						break;
					case 2:
						tmp=num*2;
						break;
					default:
						break;
				}
				if(tmp<0) continue;
				if( tmp<=100000) {
					if(v[tmp]==0) {
						q.add(tmp);
						v[tmp]=v[num]+1;
					}
					

				}
			}
			
			
		}
		
	}
	
	
}	
