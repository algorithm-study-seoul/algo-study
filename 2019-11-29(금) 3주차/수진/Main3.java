package 숨바꼭질;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main3 {
	
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
				
				//0초가 걸리는 것을 맨 먼저 탐색해나가야한다. 
				//그래야 최소 시간을 가장 먼저 탐색할 수 있다.
					case 0:
						tmp=num*2;
						break;
					case 1:
						tmp=num-1;
						break;
					case 2:
						
						tmp=num+1;
						break;
					default:
						break;
				}
				
/*
 * 인덱스 오류 조심
 * num이 10만일 경우 tmp는 20만이 된다.
 * 그러면 인덱스 오류가 나게 된다.
 * 
 * =>변수의 범위에 따라서 인덱스 범위를 꼭 생각하자!!!!!!!!!
 */
				if(tmp<0) continue;
				if( tmp<=100000) {
					if(v[tmp]==0) {
						q.add(tmp);
						if(i!=0)
							v[tmp]=v[num]+1;
						else
							v[tmp]=v[num];
					}
					

				}
			}
			
			
		}
		
	}
	
	
}	
