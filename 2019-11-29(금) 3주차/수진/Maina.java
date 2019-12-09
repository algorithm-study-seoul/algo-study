package �˰���;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
	���ͽ�Ʈ�� �˰����� ����, �ִ� �Ÿ��� ã�� ���ؼ� �� ���� �ʿ��� �������� �ֽ��ϴ�.
	
	1. visit �迭
		�ش� ������ �湮�ߴ��� ���� üũ
	2. ���� ��� Ȥ�� ����Ʈ
		�� ������ weight�� �����ϴ� ����
	3. distance �迭
		�ش� �������� �ִ� �Ÿ��� �����ϴ� �迭
	
	��ó: https://manducku.tistory.com/29 [Manducku`s Code]
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
				
				//System.out.println("Ž��: "+nr+" "+nc);
				
				
				//�湮 ó�� ���̸�  �ٷ� ����
				if(!v[nr][nc]) {
					v[nr][nc]=true;
					q.add(new point(nr,nc));
					dist[nr][nc]=dist[r][c]+map[nr][nc];

				}
				
				//�湮�ߴ� ���̸� �ִܰŸ� �� �� ����
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
