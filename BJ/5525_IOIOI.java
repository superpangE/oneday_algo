import java.util.*;
import java.io.*;
public class Main {
	
	static int N, M;
	static String str;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		str = br.readLine();
		
		int ans = 0;
		int tmp = 0;
		boolean flag = false;
		
		for (int i = 0; i < M; i++) {
			if(tmp >= ((2*N))) {
				if(!flag && str.charAt(i) == 'I') {
					flag = true;
					ans++;
				}
				else if(flag && str.charAt(i) == 'O') {
					flag = false;
				}
				else {
					tmp = 0;
					if(str.charAt(i)=='I') {
						flag = true;
						tmp = 1;
					}
					else flag = false;
				}
			}
			else {
				if(!flag && str.charAt(i) == 'I') {
					flag = true;
					tmp++;
				}
				else if(flag && str.charAt(i)=='O') {
					flag = false;
					tmp++;
				}
				else {
					tmp = 0;
					if(str.charAt(i)=='I') {
						flag = true;
						tmp = 1;
					}
					else flag = false;
				}
			}
		}
		System.out.println(ans);
	}
}
