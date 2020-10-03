% change as desired
% runtime approx (i7 @3 GHz)
% 100 episodes -- < 90 s
% 1000 episodes -- 2 - 3 min
num_trials = 1000;

% gather data -- may take time
nsmAgent = nsm_agent();
[steps_learn, ~] = nsmAgent.Trials(num_trials);

% plot nice output graphs
plot(steps_learn);
ylim([0 500]);
title('NSM Trials');
ylabel('Number of Steps until terminal');
xlabel('Episodes');