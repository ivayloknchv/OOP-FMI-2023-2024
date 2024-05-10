#pragma once
#include "Player.h"

class PremiumPlayer : public Player
{
	char* name = nullptr;

	void copyFrom(const PremiumPlayer& other);
	void moveFrom(PremiumPlayer&& other);
	void free();

	void setName(const char* name);

public:

	PremiumPlayer() = default;
	PremiumPlayer(const char* name);
	PremiumPlayer(const PremiumPlayer& other);
	PremiumPlayer& operator=(const PremiumPlayer& other);
	PremiumPlayer(PremiumPlayer&& other) noexcept;
	PremiumPlayer& operator=(PremiumPlayer&& other) noexcept;
	~PremiumPlayer() override;

	bool levelUp() override;
	const char* getName() const;
};

