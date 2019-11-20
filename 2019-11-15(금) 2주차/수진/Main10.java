package N��M;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main10 {
	
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
			
			//ù ��� ������ �� ���� ���� ������ �������� �ʴ´�.
			boolean flag=false;
			for(int j=1;j<i;j++) {
				if(arr[i]==arr[j]) {
					flag=true;
					break;
				}
					
			}
			if(!flag) {
				v[i]=true;
				dfs(i,arr[i]+" ",1);
					
				v[i]=false;
			}
			
			
			
		}
		
		System.out.println(sb);
		
		
	}

	private static void dfs(int index, String str, int count) {
		
		
		if(count==M) {
			//�� �� ���� q�� �ִ��� �ƴ��� �˻��Ѵ�.
			sb.append(str+"\n");
			return;
		}

		
		
			
			
			//�ߺ��Ǹ� �ȵȴ�.
			//
			for(int i=index+1;i<=N;i++) {
				
				
				boolean flag=false;
				
				
				
				//����ġ�� �� �� �� ���ҵ� �߿� ���� ���� �ִ��� �˻��Ѵ�.
				//���� ���Ұ� �����鼭 �湮���� ���� ���̸� => �ߺ��̶� �Ǵ�
				//���̻� ������� �ʴ´�.
				for(int j=1;j<i;j++) {
					
					
					if(arr[i]==arr[j] &&!v[j]) {
						flag=true;
						break;
					}
					
				}
				if( !v[i] && !flag) {
					
					v[i]=true;
					count++;
					
						
					dfs(i,str+arr[i]+" ",count);
						
					v[i]=false;
					count--;
				}
					
					
				
				}	
				
			
			
		
		
		
	}
}
