class Maths_helper
{
public:
	Maths_helper();

	void addition(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void addition(unsigned char *out, unsigned char *in1, unsigned int n);

	void multiplication(unsigned char *out, unsigned char *in1, unsigned char *in2);
	void multiplication(unsigned char *out, unsigned char *in, unsigned int n);

	void IntToHexa(unsigned char *out, unsigned int n);
};

