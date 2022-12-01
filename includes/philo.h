#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "limits.h"
# include "pthread.h"
# include "unistd.h"
# include "stdlib.h"
# include <sys/time.h>

//-------------------------DATA_STRUCT-----------------------
typedef enum s_state
{
	taking_fork,
	thinking,
	eating,
	sleeping,
	dead
}	t_state;

typedef struct s_philo
{
	pthread_t			instance;
	int					id;
	t_state				state;
	int					tte;
	int					ttd;
	int					tts;
	int					max_eat;
	int					eats;
	pthread_mutex_t		*ph_fork;
	pthread_mutex_t		*next_fork;
	int					is_dead;
	int					end;
	int					start_condition;
	unsigned long long	last_eat;
	unsigned long long	start_time;
	unsigned long long	cur_time;
}	t_philo;

typedef struct s_data
{
	t_philo			**philos;
	int				run_state;
	int				num_ph;
	int				*print_state;
	int				*philodeath;
}	t_data;

//------------------------FUNCTIONS----------------------------
int				start_threads(t_data *data);
long long		ft_atoi(const char *nptr);
int				init_data(t_data *data, int ac, char **av);
void			*routine(void *philo);
t_philo			*gen_philo(int i);
int				thread_end(t_data *data);
int				free_data(t_data *data);
int				assign_fork(t_data *data);
int				sleeper(int milisec, t_philo *philo);
long			mic_mil_sec(long time);
long			sec_mil_mic(long time);
void			mlock(t_philo *philo);
void			munlock(t_philo *philo);
long long		sec_to_mic(long sec);
pthread_mutex_t	*def_mutex_gen(void);
void			print_death(t_philo *philo, t_data *data);
long			time_to_mil(struct timeval time);
void			print_state(t_philo philo, struct timeval time, \
struct timeval start);
int				check_limit(char *arg);
int				check_type(char *arg);
int				arg_check(int ac, char **av);
#endif
