#ifndef two_app_scheduler
#define two_app_scheduler

#include "poncos/scheduler.hpp"

struct two_app_sched : public schedulerT {
	two_app_sched(const system_configT &system_config);
	virtual void schedule(const job_queueT &job_queue, fast::MQTT_communicator &comm, controllerT &controller,
						  std::chrono::seconds wait_time);
	virtual void command_done(const size_t config, controllerT &controller);

	// marker if a slot is in use
	std::vector<bool> co_config_in_use;
	// distgen results of a slot
	std::vector<double> co_config_distgend;
};

#endif /* end of include guard: two_app_scheduler */
