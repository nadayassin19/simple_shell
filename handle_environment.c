#include "main.h"

/**
 * _setenv - sets new env vars
 * @new_env: new var to set
 * Return: void
 */

void _setenv(char **new_env)
{
	int i;

	for (i = 0; environ[i]; i++)
		new_env[i] = _strdup(environ[i]);
	new_env[i] = NULL;
}

/**
 * free_env - free an array of env vars
 * @env: env var
 * Return: void
 */

void free_env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		free(env[i]);
}

/**
 * _getenv - gets value of an env var
 * @env_n: env var name
 * Return: env var value, NULL if it fails
 */

char *_getenv(char *env_n)
{
	size_t nameSZ, updSZ;
	char *res;
	int i, k, j;

	nameSZ = _strlen(env_n);
	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(env_n, environ[i], nameSZ) == 0)
		{
			updSZ = _strlen(environ[i]) - nameSZ;
			res = malloc(sizeof(char) * updSZ);
			if (!res)
			{
				free(res);
				perror("Allocation Error");
				return (NULL);
			}

			j = 0;
			for (k = nameSZ + 1; environ[i][k]; k++, j++)
				res[j] = environ[i][k];
			res[j] = '\0';

			return (res);
		}
	}
	return (NULL);
}
