package day0828;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;
/*
 * 기본 영역을 저장하는 arr[][] 선언
 * 장마가 1부터 100까지 왔을때의 가능/불가능 영역 체크하는 chk[][] 
 * 장마가 1부터 100까지 온다고 가정했을 때, 항상 BFS 를 돌아서 최소값 출력
 * 방문했는지를 아는 isVisited[][] 선언 및 한번 돌때마다 항상 초기화
 * 
 */
public class BJ_2468 {
	static class pos{
		int x, y;
		pos(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	static int N, arr[][], cnt;
	static boolean chk[][], isVisited[][];
	static Queue<pos>q = new LinkedList<>();
	static int dx[] = {-1, 1, 0, 0};
	static int dy[] = {0, 0, -1, 1};
	
	static boolean isValid(int x, int y) {
		return (x >= 0 && y >= 0 && x < N && y < N);
	}
	
	static void bfs() {
		while(!q.isEmpty()) {
			int x = q.peek().x;
			int y = q.peek().y;
			q.poll();
			
			for (int i = 0; i < 4; i++) {
				int mx = x + dx[i];
				int my = y + dy[i];
				if (!isValid(mx, my) || isVisited[mx][my] || !chk[mx][my]) continue;
				isVisited[mx][my] = true;
				q.add(new pos(mx, my));
			}
			
		}
	}

	public static void main(String[] args) throws Exception{
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		arr = new int[N][];
		int min = 100, max = 1, res = -1;
		for (int i = 0; i < N ;i++) {
			st = new StringTokenizer(br.readLine());
			arr[i] = new int[N];
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				if (arr[i][j] > max) max = arr[i][j];
				if (arr[i][j] < min) min = arr[i][j];
			}
		}		// 입력완료
		chk = new boolean[N][];
		isVisited = new boolean[N][];
		for (int w = min; w < max; w++) {	// 물 수위
			for (int i = 0; i < N; i++) {
				chk[i] = new boolean[N];
				isVisited[i] = new boolean[N];
				for (int j = 0; j < N; j++) {
					if (w < arr[i][j]) chk[i][j] = true;
				}
			}
			cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (!isVisited[i][j] && chk[i][j]) {
						q.add(new pos(i, j));
						isVisited[i][j] = true;
						cnt++;
						bfs();
					}
				}
			}
			//bfs();
			if (res < cnt) res = cnt;
		}
		if (min >= max) res = 1;
		System.out.println(res);
	}
}
