import java.util.*;
import java.io.*;
public class Main {

	static class box{
		int x;
		int y;
		box(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static int N, M, ans;
	static int arr[][];
	static boolean isVisited[][];
	static int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
	static int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
	static Queue<box>q = new LinkedList<>();
	
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
	
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N][M];
		isVisited = new boolean[N][M];
		
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}
	static boolean isValid(int x, int y) {
		return (x >= 0 && y >= 0 && x < N && y < M);
	}
	static void bfs() {
		boolean flag = false;
		while(!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();
			
			for (int i = 0; i < 8; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				
				if(isValid(mx, my) && arr[mx][my] > arr[x][y]) {
					flag = true;
				}
				if(isValid(mx, my) && arr[mx][my] == arr[x][y] && !isVisited[mx][my]) {
					isVisited[mx][my] = true;
					q.add(new box(mx, my));
				}
			}
		}
		if(!flag) ans++;
	}
	public static void main(String[] args) throws Exception{
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(!isVisited[i][j]) {
					isVisited[i][j] = true;
					q.add(new box(i, j));
					bfs();
				}
			}
		}
		System.out.println(ans);
	}
}
