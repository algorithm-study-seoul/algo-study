package N과M;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main4 {
	
	static int N,M;
	static boolean[] v;
	static int[] arr;
	static int count;
	
	static StringBuilder sb=new StringBuilder();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		arr=new int[N+1];
		v=new boolean[N+1];
		
		for(int i=1;i<=N;i++) {
			arr[i]=i;
		}
		
		for(int i=1;i<=N;i++) {
			dfs(i,i+" ",1);
		}
		
		System.out.println(sb);
		
		
	}

	private static void dfs(int index, String str, int count) {
		if(count==M) {
			sb.append(str+"\n");
			return;
		}
		
		
		//중복되면 안된다.
		//
		for(int i=index;i<=N;i++) {
			
				count++;
				
				dfs(i,str+i+" ",count);
				
				count--;
			
		}
		
	}
}
