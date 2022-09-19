package etc;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class 낱말퍼즐 {

	static int R = 50, C = 50, WORD_CNT = 10;
	static String [] word_list = {"apple", "parent","globe", "absolute", "puzzle", "index", "gather", "discord","squid","worldwide"};
	static boolean check [] = new boolean [WORD_CNT];
	static char [][] map = new char[R][C];
	
	public static void main(String[] args) {
		Queue<int []> q = new LinkedList<>();
		q.add(new int [] {0, 0, 1, 0}); // [r, c, d, idx]
		
		for(int i=0; i<R; i++) Arrays.fill(map[i], ' ');
		
		while(!q.isEmpty()) {
			int cur [] = q.poll();
			String curStr = word_list[cur[3]];
			
			if(isValidPos(cur[0], cur[1], cur[2], curStr)) {
				putWord(cur[0], cur[1], cur[2], curStr);
				check[cur[3]] = true;
				q.clear();
				boolean alpha [] = new boolean[26];
				
				for(int i=0; i<curStr.length(); i++) {
					char curChar = curStr.charAt(i);
					
					if(alpha[curChar - 'a']) continue;
					
					for(int j=0; j<WORD_CNT; j++) {
						if(check[j]) continue;
						if(word_list[j].charAt(0) == curChar) {
							alpha[curChar - 'a'] = true;
							
							if(cur[2] == 1) q.add(new int [] {cur[0], i + cur[1], 0, j});
							else q.add(new int [] {cur[0]+i, cur[1], 1, j});
							
							break;
						}
					}
				}
			}else { // 무인도에 넣음
				outer:for(int i=0; i<R; i++) {
					for(int j=0; j<C; j++) {
						if(map[i][j] != ' ') continue;
						
						if(isValidPos(i, j, cur[2], curStr)) {
							check[cur[3]] = true;
							putWord(i, j, cur[2], curStr);
							break outer;
						}
					}
				}
			}
			
			if(q.isEmpty()) {
				for(int i=0; i<WORD_CNT; i++) {
					if(!check[i]) {
						q.add(new int [] {0,0,cur[2] * -1, i});
						break;
					}
				}
			}
		}
		
		print();
	}
	
	static void putWord(int r, int c, int dir, String word) {
		int len = word.length();
		if(dir == 1) { // 오른쪽으로 전개
			for(int i=c; i<c+len; i++) map[r][i] = word.charAt(i - c);
		}else {
			for(int i=r; i<r+len; i++) map[i][c] = word.charAt(i - r);
		}
	}
	
	static boolean isValidPos(int r, int c, int dir, String word) {
		if(dir == 1) { // 우측으로 둬야하는 경우
			for(int i=c; i<c + word.length(); i++) {
				if(i >= C || i < 0 || (map[r][i] != ' ' && map[r][i] != word.charAt(i-c))){
					 if((r != 0 && r-1 >= 0 && map[r-1][i] != ' ') || (r != R-1 && r + 1 < R && map[r+1][i] != ' ')) {
						return false;
					 }
				}
			}
		}else { //아래로 둬야하는 경우
			//System.out.println(r + " " + c + " " + dir + " " + word);
			for(int i=r; i<r + word.length(); i++) {
				if(i >= R || i < 0 || (map[i][c] != ' ' && map[i][c] != word.charAt(i-r))) {
					 if((c != 0 && c-1 >= 0 && map[i][c-1] != ' ') || (c != C-1 && c + 1 < C && map[i][c+1] != ' ')) {
						return false;
					 }
				}
			}
		}
		
		return true;
	}
	
	static void print() {
		System.out.println("print map");
		for(int i=0; i<50; i++) {
			for(int j=0; j<50; j++) {
				System.out.print(map[i][j] + " ");
			}System.out.println();
		}
	}
}
