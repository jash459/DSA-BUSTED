class Solution {
public:
    int passThePillow(int n, int k) {
        int ballPosition = 0; // Start with child 0 holding the ball
        int direction = 1;    // Initially, the ball moves towards the right

        for (int i = 0; i < k; i++) {
            if (direction == 1) {
                if (ballPosition == n - 1)
                    direction = -1;
                ballPosition += direction;
            } else {
                if (ballPosition == 0)
                    direction = 1;
                ballPosition += direction;
            }
        }
        return ballPosition + 1;
    }
};
