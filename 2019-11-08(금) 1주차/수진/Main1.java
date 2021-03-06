package N��M;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main1 {
	
	
	static int[] arr;
	static boolean[] v;
	static int N,M;
	static int count;

	static StringBuffer sb=new StringBuffer();
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		
		arr=new int[N+1];
		v=new boolean[N+1];
		
		for(int i=1;i<=N;i++) {
			arr[i]=i;
			v[i]=false;
		}
		
		for(int i=1;i<=N;i++) {
			v[i]=true;
			
			dfs(i,i+" ",1);
			v[i]=false;
			
		}
		System.out.println(sb);
		
		
	}

	private static void dfs(int index,String str,int count) {
		
		if(count==M) {
			sb.append(str+"\n");
		}
		
		
		else {
			
			
			for(int i=1;i<=N;i++) {
				if(!v[i]) {
					v[i]=true;
					count++;
					
					dfs(i,str+i+" ",count);
					v[i]=false;
					count--;
				}
				
			}
		}
		
		
		
	}
}
