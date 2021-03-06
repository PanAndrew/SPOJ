//Login: Nukat
#include <iostream>

using namespace std;

#define MOD 1000000007

struct matrix
{
public:
	long long mat[4][4] = { { 1,0,0,0 }, { 0,1,0,0 }, { 0,0,1,0 }, { 0,0,0,1 } };
};

matrix t_array[32];

matrix mul(matrix a, matrix b)
{
	matrix temp;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp.mat[i][j] = 0;

			for (int k = 0; k < 4; k++) 
			{
				temp.mat[i][j] = (temp.mat[i][j] + a.mat[i][k] * b.mat[k][j]);
				if (temp.mat[i][j] >= MOD) temp.mat[i][j] %= MOD;
			}
		}
	}
		
	return temp;
}

matrix nth_Term(int n)
{
	int count = 0;
	matrix a;

	if (n <= 2)
		return a;

	n -= 2;

	while (n)
	{
		if (n & 1) 
		{
			a = mul(a, t_array[count]);
		}
		count++;
		n >>= 1;
	}

	return a;
}

void pre()
{
	t_array[0].mat[0][0] = 0; t_array[0].mat[0][1] = 0; t_array[0].mat[0][2] = 0; t_array[0].mat[0][3] = 1;
	t_array[0].mat[1][0] = 1; t_array[0].mat[1][1] = 0; t_array[0].mat[1][2] = 0; t_array[0].mat[1][3] = 1;
	t_array[0].mat[2][0] = 0; t_array[0].mat[2][1] = 1; t_array[0].mat[2][2] = 0; t_array[0].mat[2][3] = 1;
	t_array[0].mat[3][0] = 0; t_array[0].mat[3][1] = 0; t_array[0].mat[3][2] = 1; t_array[0].mat[3][3] = 1;

	for (int pos = 1; pos <= 29; pos++) 
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				t_array[pos].mat[i][j] = 0;

				for (int k = 0; k < 4; k++)
				{
					t_array[pos].mat[i][j] = (t_array[pos].mat[i][j] + t_array[pos - 1].mat[i][k] * t_array[pos - 1].mat[k][j]);

					if (t_array[pos].mat[i][j] >= MOD)
						t_array[pos].mat[i][j] %= MOD;
				}
			}
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	long long result1 = 0, result2, n_1, n_t, n_2;
	int m, n, result;
	long long inv = 333333336;

	matrix tmp;
	pre();

	cin >> t;

	while (t--)
	{
		cin >> m >> n;

		if (n == m)
		{
			tmp = nth_Term(n);
			cout << tmp.mat[3][2] << "\n";

			continue;
		}

		if (n <= 2)
			result1 = 0;
		else
		{
			tmp = nth_Term(n - 1);
			n_1 = tmp.mat[3][2];

			tmp = mul(tmp, t_array[0]);
			n_t = tmp.mat[3][2];

			tmp = mul(tmp, t_array[1]);
			n_2 = tmp.mat[3][2];

			result1 = (n_2 + (n_t << 1) + n_1 - 1);

			result1 = (result1*inv) % MOD;
		}

		if (m <= 3)
			result2 = 0;
		else
		{
			m--;
			tmp = nth_Term(m - 1);
			n_1 = tmp.mat[3][2];

			tmp = mul(tmp, t_array[0]);
			n_t = tmp.mat[3][2];

			tmp = mul(tmp, t_array[1]);
			n_2 = tmp.mat[3][2];

			result2 = (n_2 + (n_t << 1) + n_1 - 1);

			result2 = (result2*inv) % MOD;
		}

		result = (result1 - result2 + MOD) % MOD;
		cout << result << "\n";
	}

	return 0;
}