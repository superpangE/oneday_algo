package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_1158 {
	
	static int T, x, y, res;
	static String text, N;
	static boolean flag;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for (int TC = 1; TC <= 10; TC++) {
			flag = false;
			T = Integer.parseInt(br.readLine());
			for (int num = 1; num <= T; num++) {
				text = br.readLine();
				StringTokenizer st = new StringTokenizer(text);
				st.nextToken();
				N = st.nextToken();
				char tmp = N.charAt(0);
				if (tmp == '-' || tmp == '+' || tmp =='*' || tmp == '/') {
					if (!st.hasMoreTokens())
						flag = true;
				}
				else {
					if (st.hasMoreTokens())
						flag = true;
				}
			}
			if (flag)
				System.out.println("#" + TC + " 0");
			else
				System.out.println("#" + TC + " 1");
		}
		br.close();
	}
}
