class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character,Integer> map = new HashMap<>();
        for (int i = 0; i != magazine.length(); ++i) {
            if (map.containsKey(magazine.charAt(i))) {
                Integer v = map.get(magazine.charAt(i)) + 1;
                map.put(magazine.charAt(i), v);
            }  else {
                map.put(magazine.charAt(i), 1);
            }
        }
        
        for (int i = 0; i != ransomNote.length(); ++i) {
            Character k = ransomNote.charAt(i);
            if (map.containsKey(k)) { 
                Integer v = map.get(k) - 1;
                map.put(k, v);
                if (map.get(k) < 0) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
}