#include "match.h"
#include "map.h"
map::map()
{
    len = 0;
}
void map::remove(int key)
{
    for (int i = 0; i < this->len; i++)
    {
        if (this->mat[i]->key == key)
        {
            delete this->mat[i];
            for (int k = i; k < this->len; k++)
            {
                this->mat[k] = this->mat[k + 1];
            }
            this->len--;
        }
    }
}
void map::add(int key, int value)
{
    for (int i = 0; i < this->len; i++)
    {
        if (this->mat[i]->key == key || this->mat[i]->value == value)
            return;
    }
    mat[len++] = new Match(key, value);
}

int map::operator[](int key)
{
    for (int i = 0; i < this->len; i++)
    {
        if (this->mat[i]->key == key)
            return this->mat[i]->value;
    }
    return 0;
}
void map::clear()
{
    for (int i = 0; i < this->len; i++)
    {
        delete this->mat[i];
    }
    len = 0;
}