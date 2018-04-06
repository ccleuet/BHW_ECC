class Maths_helper
{
private :
	unsigned char *p;

public:
	Maths_helper();
	Maths_helper(unsigned char *p);

	unsigned char*  get_p();
	void set_p(unsigned char *p);

	void addition(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void addition(unsigned char *out, unsigned char *in1, unsigned int n);

	void soustraction_10(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void soustraction_10(unsigned char *out, unsigned char *in1, unsigned int n);

	void soustraction_20(unsigned char *out, unsigned char *in1, unsigned char *in2);

	void multiplication(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void multiplication(unsigned char *out, unsigned char *in, int n);

	void modular_division(unsigned char *out, unsigned char *in, int n);
	void modular_division(unsigned char *out, unsigned char *in1, unsigned char *in2);

	void division(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void division(unsigned char *out, unsigned char *in1, unsigned int n);

	void modulo_10(unsigned char *in);
	void modulo_20(unsigned char *in);

	void modular_inverse(unsigned char *out, unsigned char *in);
	void modular_inverse(unsigned char *out, int n);

	void intToHexa(unsigned char *out, unsigned int n);
	bool is_Greater(unsigned char *in1, unsigned char *in2, int n);
	void shift_left(unsigned char *in, unsigned int n);
	void init(unsigned char *in, int n);

	void tenTo_20hexa(unsigned char *out, unsigned char *in);
	void twentyTo_10hexa(unsigned char *out, unsigned char *in);

	bool isEqual(unsigned char *in1, unsigned char *in2);
	bool isNull(unsigned char *in);
};

