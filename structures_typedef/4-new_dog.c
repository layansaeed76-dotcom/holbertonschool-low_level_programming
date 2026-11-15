#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *dog;
	int len_n = 0, len_o = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);

	while (name[len_n] != '\0')
		len_n++;
	while (owner[len_o] != '\0')
		len_o++;

	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	dog->name = malloc(sizeof(char) * (len_n + 1));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (len_o + 1));
	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	for (i = 0; i <= len_n; i++)
		dog->name[i] = name[i];
	for (i = 0; i <= len_o; i++)
		dog->owner[i] = owner[i];
	dog->age = age;

	return (dog);
}
