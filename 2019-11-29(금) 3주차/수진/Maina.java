package 알고스팟;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
	다익스트라 알고리즘을 통해, 최단 거리를 찾기 위해선 몇 가지 필요한 변수들이 있습니다.
	
	1. visit 배열
		해당 엣지를 방문했는지 여부 체크
	2. 인접 행렬 혹은 리스트
		각 엣지별 weight를 저장하는 영역
	3. distance 배열
		해당 노드까지의 최단 거리를 저장하는 배열
	
	출처: https://manducku.tistory.com/29 [Manducku`s Code]
*
*/	

public class Main {
	static int N,M;
	static int[][] map;
	static boolean[][] v;
	static int[][] dist;
	static int[] dx= {-1,0,1,0};
	static int[] dy= {0,1,0,-1};
	static int min=Integer.MAX_VALUE;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		
		StringTokenizer st=new StringTokenizer(br.readLine().trim()," ");
		M=Integer.parseInt(st.nextToken());
		N=Integer.parseInt(st.nextToken());
		map=new int[N][M];
		v=new boolean[N][M];
		dist=new int[N][M];
		
		
		for(int i=0;i<N;i++) {
			 String str=br.readLine().trim();
			 for(int j=0;j<M;j++) {
				 map[i][j]=str.toCharArray()[j]-'0';
				 dist[i][j]=Integer.MAX_VALUE;
			 }
		}
		
		
		bfs();
		System.out.println(min);
		
	}

	private static void bfs() {
		Queue<point> q=new LinkedList<point>();
		
		q.add(new point(0,0));
		v[0][0]=true;
		dist[0][0]=0;
		
		while(!q.isEmpty()) {
			
			point p=q.poll();
			int r=p.x;
			int c=p.y;
			//System.out.println(p.toString());
			
			if(r==N-1 && c==M-1) {
				min=Integer.min(min, dist[r][c]);
				
				
			}
			
			for(int i=0;i<4;i++) {
				int nr=p.x+dx[i];
				int nc=p.y+dy[i];
				
				if(nr<0||nr>=N||nc<0||nc>=M)continue;
				
				//System.out.println("탐색: "+nr+" "+nc);
				
				
				//방문 처음 점이면  바로 삽입
				if(!v[nr][nc]) {
					v[nr][nc]=true;
					q.add(new point(nr,nc));
					dist[nr][nc]=dist[r][c]+map[nr][nc];

				}
				
				//방문했던 덤이면 최단거리 비교 후 삽입
				else {
					if(dist[r][c]+map[nr][nc]<dist[nr][nc]) {
						dist[nr][nc]=dist[r][c]+map[nr][nc];
						q.add(new point(nr,nc));
					}
				}
				
			}
		}
		
		
	}
	
	static class point{
		public int x;
		public int y;
		public point(int x, int y) {
			super();
			this.x = x;
			this.y = y;

		}
		@Override
		public String toString() {
			return "point [x=" + x + ", y=" + y + "]";
		}
	
		
	}
	

}
