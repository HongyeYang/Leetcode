class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int MA=max(A,E),MB=max(B,F),MC=min(C,G),MD=min(D,H);
        int over=0;
        if(MC>MA&&MD>MB)over=(MC-MA)*(MD-MB);
        return (C-A)*(D-B)+(G-E)*(H-F)-over;
    }
};
