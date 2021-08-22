package com.ssafy;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

/*
 * bool 을 26크기만큼 선언
 * stack 에 하나씩 넣으면서 bool이 체크되어있는지 확인
 * stack top 을 확인하면서 같은거라면 넘어가기. 다른거라면 chk 확인
 */

public class BJ_1316 {
	static int N, cnt;
	static String text;
	static Stack<Character>s = new Stack<>();
	static boolean arr[], flag;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		cnt = 0;
		N = Integer.parseInt(br.readLine());
		for (int i = 0; i < N; i++) {
			flag = false;
			arr = new boolean[26];
			for (int j = 0; j < 26; j++) {
				arr[j] = false;
			}
			text = br.readLine();	// 입력 완료
			s.push(text.charAt(0));
			arr[text.charAt(0) - 97] = true;	// 첫번째 값은 따로 처리
			for (int j = 1; j < text.length(); j++) {	
				if (text.charAt(j) == s.peek()) continue;	// stack top 과 같다면 continue
				else {
					if (arr[text.charAt(j) - 97] == false) {	// 다른값이 처음으로 나왔을 때
						s.push(text.charAt(j));
						arr[text.charAt(j) - 97] = true;
					}
					else {
						flag = true;
						break;
					}			// 안되는 경우는 flag true
				}
				
			}
			s.clear();
			if (flag == false)
				cnt++;
		}
		System.out.println(cnt);
	}
}
