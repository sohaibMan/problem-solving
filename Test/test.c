int numSteps(char *s)
{
    int numStep = 0;
    while (!(strlen(s) == 1 && s[0] == '1'))
    {
        numStep++;
        if ((s[strlen(s) - 1] - '0') & 0x01)
        {
            for (int i = 0; i < strlen(s); i++)
            {
                s[i] = (s[i] - '0') >> 1 | (i < strlen(s) - 1 ? (s[i + 1] - '0') << (8 - 1) : 0);
            }
        }
        else
        {
            int i;

            for (i = strlen(s) - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    s[i] = '1';
                    break;
                }
                else
                {
                    s[i] = '0';
                }
            }
        }
    }
    return numStep;
}
