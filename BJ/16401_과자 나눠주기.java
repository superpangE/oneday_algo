import java.util.*;
import java.io.*;;

/*
 * M 보다 수가 많다면 left가 center + 1 이 됨
 * M 보다 수가 적다면 right가 center
 */
public class Main {
	static int N, M, l = 1, r = 1000000000;
	static int[] arr;
	static void init() throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
	}
	
	static void binary() {
		while(true) {
			if(l >= r) {
				System.out.println(l-1);
				return;
			}
			
			
			int c = (l + r) / 2;
			int cal = 0;
			for (int i = 0; i < N; i++) {
				cal += (arr[i] / c);
			}
			
			if(M > cal) r = c;
			else l = c+1;
		}
	}
	
	public static void main(String[] args) throws Exception{
		init();
		binary();
	}
}
