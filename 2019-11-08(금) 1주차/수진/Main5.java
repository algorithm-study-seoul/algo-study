
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main5 {
	
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
		
		st=new StringTokenizer(br.readLine().trim()," ");
		for(int i=1;i<=N;i++) {
			arr[i]=Integer.parseInt(st.nextToken());
		}
		
		
		Arrays.parallelSort(arr);
		
		
		for(int i=1;i<=N;i++) {
			v[i]=true;
			dfs(i,arr[i]+" ",1);
			v[i]=false;
		}
		
		System.out.println(sb);
		
		
	}

	private static void dfs(int index, String str, int count) {
		if(count==M) {
			sb.append(str+"\n");
			return;
		}
		
		
		//Áßº¹µÇ¸é ¾ÈµÈ´Ù.
		//
		for(int i=1;i<=N;i++) {
			
			if(!v[i]) {
				count++;
				v[i]=true;
				
				dfs(i,str+arr[i]+" ",count);
				
				count--;
				v[i]=false;
			}
				
			
		}
		
	}
}
