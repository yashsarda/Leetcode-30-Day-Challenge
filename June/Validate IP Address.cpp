/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255,
 separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":").
For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits
and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros
and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity.
For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.
 */
 class Solution {
 public:
     vector<string> getTokens(string value, char delimiter)
     {
         vector<string> tokens;
         stringstream ss(value);
         string line;
         while(getline(ss, line, delimiter)) {
             tokens.push_back(line);
         }
         return tokens;
     }
     int count(string IP, char delimiter)
     {
         int counter = 0;
         for(int i = 0; i < IP.size(); i++)
             counter += (IP[i] == delimiter);
         return counter;
     }
     int convert(string value)
     {
         stringstream ss(value);
         int x;
         ss >> x;
         return x;
     }
     bool validateip4(string IP)
     {
         vector<string> tokens = getTokens(IP, '.');
         int counter = count(IP, '.');

         if(counter != 3 || tokens.size() != 4)
             return false;

         for(int i = 0; i < 4; i++) {
             int si = tokens[i].size();
             if(si == 0 || si > 3)
                 return false;

             if(tokens[i][0] == '0' && si > 1)
                 return false;

             for(int j = 0; j < si; j++) {
                 if(!(tokens[i][j] >= '0' && tokens[i][j] <= '9'))
                     return false;
             }
             int value = convert(tokens[i]);
             if(!(value >= 0 && value <= 255))
                 return false;
         }
         return true;
     }
     bool validateip6(string IP)
     {
         vector<string> tokens = getTokens(IP, ':');
         int counter = count(IP, ':');

         if(counter != 7 || tokens.size() != 8)
             return false;

         for(int i = 0; i < 8; i++) {
             int si = tokens[i].size();
             if(si == 0 || si > 4)
                 return false;

             for(int j = 0; j < si; j++) {
                 char c = tokens[i][j];
                 if(c >= '0' && c <= '9' || c >= 'a' && c <= 'f' || c >= 'A' && c <= 'F')
                     continue;
                 return false;
             }
         }
         return true;
     }
     string validIPAddress(string IP) {
         int len = IP.size();
         string answer = "";
         if(IP.find(":") == string::npos) {
             //ipv4
             bool ipv4 = validateip4(IP);
             answer = (ipv4 ? "IPv4" : "Neither");
         }
         else {
             //ipv6
             bool ipv6 = validateip6(IP);
             answer = (ipv6 ? "IPv6" : "Neither");
         }
         return answer;
     }
 };
