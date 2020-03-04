#include <iostream>
#include <typeinfo>

class Firma
{
public:
	int do_uregulowania = 0;
	void uregulowana();

	virtual ~Firma() = default;
};

class Dostawca :public Firma
{
public:
	virtual void dostawa() = 0;
};

class Nabywca :public Firma
{
public:
	virtual void sprzedaz() = 0;
};

class Detal :public Nabywca
{
public:
	void sprzedaz() override;
};

class Hurt :public Nabywca
{
public:
	void sprzedaz() override;
};

class Komputery :public Dostawca
{
public:
	void dostawa() override;
};

class Sluchawki :public Dostawca
{
public:
	void dostawa() override;
};