package N°úM;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main2 {
	
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
			v[i]=true;
			dfs(i,i+" ",1);
			
		}
		
		System.out.println(sb);
		
		
	}

	private static void dfs(int index, String str, int count) {
		if(count==M) {
			sb.append(str+"\n");
		}
		
		for(int i=index;i<=N;i++) {
			
			if(!v[i]) {
				count++;
				v[i]=true;
				
				dfs(i,str+i+" ",count);
				
				count--;
				v[i]=false;
			}
		}
		
	}
}
