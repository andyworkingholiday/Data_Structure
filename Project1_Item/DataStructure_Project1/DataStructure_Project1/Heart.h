#pragma once

class Heart {
public:
	Heart() {
		Board[0] = "¢¾";
		Board[1] = "¢½";
	};

	~Heart() {};

	void Like() {
		printf("%s\n", Board[0]);
	}

	void UnLike() {
		printf("%s\n", Board[1]);
	}

private:
	const char* Board[2];
};
