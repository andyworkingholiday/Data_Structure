#pragma once

class Heart {
public:
	Heart() {
		Board[0] = "��";
		Board[1] = "��";
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
