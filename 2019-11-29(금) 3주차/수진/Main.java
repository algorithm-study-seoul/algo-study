package 토마토;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int N,M;
	static int[][] tom;
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,1,0,-1};
	static Queue<point> q=new LinkedList<point>();
			
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		
		N=Integer.parseInt(st.nextToken());
		M=Integer.parseInt(st.nextToken());
		tom=new int[M][N];
		
		
		for(int i=0;i<M;i++) {
			
			st=new StringTokenizer(br.readLine().trim()," ");
			for(int j=0;j<N;j++) {
				tom[i][j]=Integer.parseInt(st.nextToken());
				if(tom[i][j]==1) {
					q.add(new point(i,j,1));
				}
			}
		}
		
		
		//토마토 익게하기
		bfs();
		//검사
		
		int max=Integer.MIN_VALUE;
		
		forout:
		for(int i=0;i<M;i++) {
			
			for(int j=0;j<N;j++) {
				if(tom[i][j]==0) {
					max=-1;
					break forout;
				}
				if(max<tom[i][j]) {
					max=tom[i][j];
					
				}
			}
		}
		
		if(max==-1)System.out.println("-1");
		else System.out.println(max-1);
	}
	
	private static void bfs() {
		
		while(!q.isEmpty()) {
			point p=q.poll();
			
			
			for(int i=0;i<4;i++) {
				int nx=p.x+dx[i];
				int ny=p.y+dy[i];
				
				if(nx<0||nx>=M||ny<0||ny>=N) {
					continue;
				}
				
				else if( tom[nx][ny]==0) {
					tom[nx][ny]=p.count+1;
					
					q.add(new point(nx,ny,p.count+1));
					
					
				}
			}
		}
	}

	public static class point{
		public int x,y;
		public int count;

		public point(int x, int y,int count) {
			super();
			this.x = x;
			this.y = y;
			this.count = count;
		}

		@Override
		public String toString() {
			return "point [x=" + x + ", y=" + y + ", count=" + count + "]";
		}

		

		
		
	}

}
