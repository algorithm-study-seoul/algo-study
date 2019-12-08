package 이모티콘;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

	static int S;
	static int mintime;
	static Queue<set> q=new LinkedList<set>();
	static int[][] visit=new int[1001][1001];
	static int count=0;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		
		S=Integer.parseInt(br.readLine().trim());
		
		q.add(new set(1,false,0,0));
		visit[S][0]=1;
		
		bfs();
		
	}
	
	

	private static void bfs() {
		
		
		while(!q.isEmpty()) {
			
			set num=q.poll();
			
			
			
			if(num.num==S) {
				System.out.println(num.t);
				return;
			}
			
			for(int i=0;i<3;i++) {
				int tmp=0;
				int v=0;
				boolean flag=num.v;
				switch(i){
					case 0:
						v=num.num;
						tmp=num.num;
						flag=true;
						break;
					case 1:
						if(num.v==false) {
							continue;
						}else {
							tmp=num.num+num.vnum;
							v=num.vnum;
						}
						break;
					case 2:
						tmp=num.num-1;
						v=num.vnum;
						break;
					default:
							break;
							
				}
				if(tmp>1000 || tmp<1) continue;
				if(visit[tmp][v]==1) continue;
				
				q.add(new set(tmp,flag,v,num.t+1));
				visit[tmp][v]=1;

				
					

	
				}
				
			}

		}
		
	
	
	static class set{
		int num;
		boolean v;
		int vnum;
		int t;
		public set(int num, boolean v, int vnum, int t) {
			super();
			this.num = num;
			this.v = v;
			this.vnum = vnum;
			this.t = t;
		}
		@Override
		public String toString() {
			return "set [num=" + num + ", v=" + v + ", vnum=" + vnum + ", t=" + t + "]";
		}
		
	}
	

}
