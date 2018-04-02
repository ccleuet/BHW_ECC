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

	void soustraction(unsigned char *out, unsigned char *in1, unsigned char *in2);

	void multiplication(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void multiplication(unsigned char *out, unsigned char *in, unsigned int n);

	void IntToHexa(unsigned char *out, unsigned int n);
	bool Is_Greater(unsigned char *in1, unsigned char *in2);
	void Shift_left(unsigned char *in, unsigned int n);
	void Init(unsigned char *in);
};

