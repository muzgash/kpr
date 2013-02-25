#ifndef DECISIONFUNCTIONS_HPP
#define DECISION FUNCTIONS_HPP

#include<vector>

/*! \brief Looks iMemory steps behind in viHistory and if it's too crowded returns false.
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bSame(std::vector<int> viHistory, int iMemory);

/*! \brief Looks iMemory steps behind in viHistory and if it's too crowded returns true.
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bDiff(std::vector<int> viHistory, int iMemory);

/*! \brief Looks iMemory steps in viHistory and takes the mean value of them all, and if it's too crowded returns false.
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bTrend(std::vector<int> viHistory,int iMemory);

/*! \brief Looks iMemory steps in viHistory and sums 10 to that value
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bSum(std::vector<int> viHistory,int iMemory);

/*! \brief Looks iMemory steps in viHistory and add its 30% to the total of people
 *
 *  \param vector<int> History.
 *  \param int Memory.
 *
 *  \returns bool Decision.
 */
bool bPercent(std::vector<int> viHistory,int iMemory);

#endif

