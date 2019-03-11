open WebhookTypes;

type protocol =
  | Http
  | Https;

type webhookEvent('a) = {
  id: string,
  name: string,
  payload: 'a,
  protocol,
  host: option(string),
  url: option(string),
};

type transformFn('a) = webhookEvent('a) => webhookEvent('a);

type webhookOptions('a) = {
  secret: string,
  path: option(string),
  transform: option(transformFn('a)),
};

type t;

[@bs.module] [@bs.new]
external createWebhook: option(webhookOptions(Js.Types.obj_val)) => t =
  "@octokit/webhooks";

[@bs.send]
external on_check_run:
  (
    t,
    [@bs.string] [
      | [@bs.as "check_run"] `all(
          webhookEvent(webhookPayloadCheckRun) => unit,
        )
      | [@bs.as "check_run.completed"] `completed(
          webhookEvent(webhookPayloadCheckRun) => unit,
        )
      | [@bs.as "check_run.created"] `created(
          webhookEvent(webhookPayloadCheckRun) => unit,
        )
      | [@bs.as "check_run.requested_action"] `requested_action(
          webhookEvent(webhookPayloadCheckRun) => unit,
        )
      | [@bs.as "check_run.rerequested"] `rerequested(
          webhookEvent(webhookPayloadCheckRun) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_check_suite:
  (
    t,
    [@bs.string] [
      | [@bs.as "check_suite"] `all(
          webhookEvent(webhookPayloadCheckSuite) => unit,
        )
      | [@bs.as "check_suite.completed"] `completed(
          webhookEvent(webhookPayloadCheckSuite) => unit,
        )
      | [@bs.as "check_suite.requested"] `requested(
          webhookEvent(webhookPayloadCheckSuite) => unit,
        )
      | [@bs.as "check_suite.rerequested"] `rerequested(
          webhookEvent(webhookPayloadCheckSuite) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_commit_comment:
  (
    t,
    [@bs.string] [
      | [@bs.as "commit_comment"] `all(
          webhookEvent(webhookPayloadCommitComment) => unit,
        )
      | [@bs.as "commit_comment.created"] `created(
          webhookEvent(webhookPayloadCommitComment) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_create:
  (
    t,
    [@bs.string] [
      | [@bs.as "create"] `all(webhookEvent(webhookPayloadCreate) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_delete:
  (
    t,
    [@bs.string] [
      | [@bs.as "delete"] `all(webhookEvent(webhookPayloadDelete) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_deployment:
  (
    t,
    [@bs.string] [
      | [@bs.as "deployment"] `all(
          webhookEvent(webhookPayloadDeployment) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_deployment_status:
  (
    t,
    [@bs.string] [
      | [@bs.as "deployment_status"] `all(
          webhookEvent(webhookPayloadDeploymentStatus) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_fork:
  (
    t,
    [@bs.string] [
      | [@bs.as "fork"] `all(webhookEvent(webhookPayloadFork) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_github_app_authorization:
  (
    t,
    [@bs.string] [
      | [@bs.as "github_app_authorization"] `all(
          webhookEvent(webhookPayloadGithubAppAuthorization) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_gollum:
  (
    t,
    [@bs.string] [
      | [@bs.as "gollum"] `all(webhookEvent(webhookPayloadGollum) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_installation:
  (
    t,
    [@bs.string] [
      | [@bs.as "installation"] `all(
          webhookEvent(webhookPayloadInstallation) => unit,
        )
      | [@bs.as "installation.created"] `created(
          webhookEvent(webhookPayloadInstallation) => unit,
        )
      | [@bs.as "installation.deleted"] `deleted(
          webhookEvent(webhookPayloadInstallation) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_issue_comment:
  (
    t,
    [@bs.string] [
      | [@bs.as "issue_comment"] `all(
          webhookEvent(webhookPayloadIssueComment) => unit,
        )
      | [@bs.as "issue_comment.created"] `created(
          webhookEvent(webhookPayloadIssueComment) => unit,
        )
      | [@bs.as "issue_comment.deleted"] `deleted(
          webhookEvent(webhookPayloadIssueComment) => unit,
        )
      | [@bs.as "issue_comment.edited"] `edited(
          webhookEvent(webhookPayloadIssueComment) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_issues:
  (
    t,
    [@bs.string] [
      | [@bs.as "issues"] `all(webhookEvent(webhookPayloadIssues) => unit)
      | [@bs.as "issues.assigned"] `assigned(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.closed"] `closed(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.deleted"] `deleted(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.demilestoned"] `demilestoned(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.edited"] `edited(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.labeled"] `labeled(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.milestoned"] `milestoned(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.opened"] `opened(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.reopened"] `reopened(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.transferred"] `transferred(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.unassigned"] `unassigned(
          webhookEvent(webhookPayloadIssues) => unit,
        )
      | [@bs.as "issues.unlabeled"] `unlabeled(
          webhookEvent(webhookPayloadIssues) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_label:
  (
    t,
    [@bs.string] [
      | [@bs.as "label"] `all(webhookEvent(webhookPayloadLabel) => unit)
      | [@bs.as "label.created"] `created(
          webhookEvent(webhookPayloadLabel) => unit,
        )
      | [@bs.as "label.deleted"] `deleted(
          webhookEvent(webhookPayloadLabel) => unit,
        )
      | [@bs.as "label.edited"] `edited(
          webhookEvent(webhookPayloadLabel) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_marketplace_purchase:
  (
    t,
    [@bs.string] [
      | [@bs.as "marketplace_purchase"] `all(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | [@bs.as "marketplace_purchase.cancelled"] `canceled(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | [@bs.as "marketplace_purchase.changed"] `changed(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | [@bs.as "marketplace_purchase.pending_change"] `pending_change(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | [@bs.as "marketplace_purchase.pending_change_cancelled"]
        `pending_change_cancelled(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
      | [@bs.as "marketplace_purchase.purchased"] `purchased(
          webhookEvent(webhookPayloadMarketplacePurchase) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_member:
  (
    t,
    [@bs.string] [
      | [@bs.as "member"] `all(webhookEvent(webhookPayloadMember) => unit)
      | [@bs.as "member.added"] `added(
          webhookEvent(webhookPayloadMember) => unit,
        )
      | [@bs.as "member.deleted"] `deleted(
          webhookEvent(webhookPayloadMember) => unit,
        )
      | [@bs.as "member.edited"] `edited(
          webhookEvent(webhookPayloadMember) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_milestone:
  (
    t,
    [@bs.string] [
      | [@bs.as "milestone"] `all(
          webhookEvent(webhookPayloadMilestone) => unit,
        )
      | [@bs.as "milestone.closed"] `closed(
          webhookEvent(webhookPayloadMilestone) => unit,
        )
      | [@bs.as "milestone.created"] `created(
          webhookEvent(webhookPayloadMilestone) => unit,
        )
      | [@bs.as "milestone.deleted"] `deleted(
          webhookEvent(webhookPayloadMilestone) => unit,
        )
      | [@bs.as "milestone.edited"] `edited(
          webhookEvent(webhookPayloadMilestone) => unit,
        )
      | [@bs.as "milestone.opened"] `opened(
          webhookEvent(webhookPayloadMilestone) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_organization:
  (
    t,
    [@bs.string] [
      | [@bs.as "organization"] `all(
          webhookEvent(webhookPayloadOrganization) => unit,
        )
      | [@bs.as "organization.member_added"] `member_added(
          webhookEvent(webhookPayloadOrganization) => unit,
        )
      | [@bs.as "organization.member_invited"] `member_invited(
          webhookEvent(webhookPayloadOrganization) => unit,
        )
      | [@bs.as "organization.member_removed"] `member_removed(
          webhookEvent(webhookPayloadOrganization) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_org_block:
  (
    t,
    [@bs.string] [
      | [@bs.as "org_block"] `all(
          webhookEvent(webhookPayloadOrgBlock) => unit,
        )
      | [@bs.as "org_block.blocked"] `blocked(
          webhookEvent(webhookPayloadOrgBlock) => unit,
        )
      | [@bs.as "org_block.unblocked"] `unblocked(
          webhookEvent(webhookPayloadOrgBlock) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_page_build:
  (
    t,
    [@bs.string] [
      | [@bs.as "page_build"] `all(
          webhookEvent(webhookPayloadPageBuild) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_project_card:
  (
    t,
    [@bs.string] [
      | [@bs.as "project_card"] `all(
          webhookEvent(webhookPayloadProjectCard) => unit,
        )
      | [@bs.as "project_card.converted"] `converted(
          webhookEvent(webhookPayloadProjectCard) => unit,
        )
      | [@bs.as "project_card.created"] `created(
          webhookEvent(webhookPayloadProjectCard) => unit,
        )
      | [@bs.as "project_card.deleted"] `deleted(
          webhookEvent(webhookPayloadProjectCard) => unit,
        )
      | [@bs.as "project_card.edited"] `edited(
          webhookEvent(webhookPayloadProjectCard) => unit,
        )
      | [@bs.as "project_card.moved"] `moved(
          webhookEvent(webhookPayloadProjectCard) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_project_column:
  (
    t,
    [@bs.string] [
      | [@bs.as "project_column"] `all(
          webhookEvent(webhookPayloadProjectColumn) => unit,
        )
      | [@bs.as "project_column.created"] `created(
          webhookEvent(webhookPayloadProjectColumn) => unit,
        )
      | [@bs.as "project_column.deleted"] `deleted(
          webhookEvent(webhookPayloadProjectColumn) => unit,
        )
      | [@bs.as "project_column.edited"] `edited(
          webhookEvent(webhookPayloadProjectColumn) => unit,
        )
      | [@bs.as "project_column.moved"] `moved(
          webhookEvent(webhookPayloadProjectColumn) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_project:
  (
    t,
    [@bs.string] [
      | [@bs.as "project"] `all(webhookEvent(webhookPayloadProject) => unit)
      | [@bs.as "project.closed"] `closed(
          webhookEvent(webhookPayloadProject) => unit,
        )
      | [@bs.as "project.created"] `created(
          webhookEvent(webhookPayloadProject) => unit,
        )
      | [@bs.as "project.deleted"] `deleted(
          webhookEvent(webhookPayloadProject) => unit,
        )
      | [@bs.as "project.edited"] `edited(
          webhookEvent(webhookPayloadProject) => unit,
        )
      | [@bs.as "project.reopened"] `reopened(
          webhookEvent(webhookPayloadProject) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_public:
  (
    t,
    [@bs.string] [
      | [@bs.as "public"] `all(webhookEvent(webhookPayloadPublic) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_pull_request:
  (
    t,
    [@bs.string] [
      | [@bs.as "pull_request"] `all(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.assigned"] `assigned(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.closed"] `closed(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.edited"] `edited(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.labeled"] `labeled(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.openend"] `openend(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.reopened"] `reopened(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.review_request_removed"] `review_request_removed(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.review_requested"] `review_requested(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.unassigned"] `unassigned(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.unlabeled"] `unlabeled(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
      | [@bs.as "pull_request.synchronize"] `synchronize(
          webhookEvent(webhookPayloadPullRequest) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_pull_request_review:
  (
    t,
    [@bs.string] [
      | [@bs.as "pull_request_review"] `all(
          webhookEvent(webhookPayloadPullRequestReview) => unit,
        )
      | [@bs.as "pull_request_review.dismissed"] `dismissed(
          webhookEvent(webhookPayloadPullRequestReview) => unit,
        )
      | [@bs.as "pull_request_review.edited"] `edited(
          webhookEvent(webhookPayloadPullRequestReview) => unit,
        )
      | [@bs.as "pull_request_review.submitted"] `submitted(
          webhookEvent(webhookPayloadPullRequestReview) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_pull_request_review_comment:
  (
    t,
    [@bs.string] [
      | [@bs.as "pull_request_review_comment"] `all(
          webhookEvent(webhookPayloadPullRequestReviewComment) => unit,
        )
      | [@bs.as "pull_request_review_comment.created"] `created(
          webhookEvent(webhookPayloadPullRequestReviewComment) => unit,
        )
      | [@bs.as "pull_request_review_comment.deleted"] `deleted(
          webhookEvent(webhookPayloadPullRequestReviewComment) => unit,
        )
      | [@bs.as "pull_request_review_comment.edited"] `edited(
          webhookEvent(webhookPayloadPullRequestReviewComment) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_push:
  (
    t,
    [@bs.string] [
      | [@bs.as "push"] `all(webhookEvent(webhookPayloadPush) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_release:
  (
    t,
    [@bs.string] [
      | [@bs.as "release"] `all(webhookEvent(webhookPayloadRelease) => unit)
      | [@bs.as "release.published"] `published(
          webhookEvent(webhookPayloadRelease) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_repository:
  (
    t,
    [@bs.string] [
      | [@bs.as "repository"] `all(
          webhookEvent(webhookPayloadRepository) => unit,
        )
      | [@bs.as "repository.archived"] `archived(
          webhookEvent(webhookPayloadRepository) => unit,
        )
      | [@bs.as "repository.created"] `created(
          webhookEvent(webhookPayloadRepository) => unit,
        )
      | [@bs.as "repository.deleted"] `deleted(
          webhookEvent(webhookPayloadRepository) => unit,
        )
      | [@bs.as "repository.privatized"] `privatized(
          webhookEvent(webhookPayloadRepository) => unit,
        )
      | [@bs.as "repository.publicized"] `publicized(
          webhookEvent(webhookPayloadRepository) => unit,
        )
      | [@bs.as "repository.unarchived"] `unarchived(
          webhookEvent(webhookPayloadRepository) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_repository_import:
  (
    t,
    [@bs.string] [
      | [@bs.as "repository_import"] `all(
          webhookEvent(webhookPayloadRepositoryImport) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_repository_vulnerability_alert:
  (
    t,
    [@bs.string] [
      | [@bs.as "repository_vulnerability_alert"] `all(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
      | [@bs.as "repository_vulnerability_alert.create"] `create(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
      | [@bs.as "repository_vulnerability_alert.dismiss"] `dismiss(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
      | [@bs.as "repository_vulnerability_alert.resolve"] `resolve(
          webhookEvent(webhookPayloadRepositoryVulnerabilityAlert) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_security_advisory:
  (
    t,
    [@bs.string] [
      | [@bs.as "security_advisory"] `all(
          webhookEvent(webhookPayloadSecurityAdvisory) => unit,
        )
      | [@bs.as "security_advisory.performed"] `performed(
          webhookEvent(webhookPayloadSecurityAdvisory) => unit,
        )
      | [@bs.as "security_advisory.published"] `published(
          webhookEvent(webhookPayloadSecurityAdvisory) => unit,
        )
      | [@bs.as "security_advisory.updated"] `updated(
          webhookEvent(webhookPayloadSecurityAdvisory) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_status:
  (
    t,
    [@bs.string] [
      | [@bs.as "status"] `all(webhookEvent(webhookPayloadStatus) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_team:
  (
    t,
    [@bs.string] [
      | [@bs.as "team"] `all(webhookEvent(webhookPayloadTeam) => unit)
      | [@bs.as "team.performed.added_to_repository"] `added_to_repository(
          webhookEvent(webhookPayloadTeam) => unit,
        )
      | [@bs.as "team.performed.created"] `created(
          webhookEvent(webhookPayloadTeam) => unit,
        )
      | [@bs.as "team.performed.deleted"] `deleted(
          webhookEvent(webhookPayloadTeam) => unit,
        )
      | [@bs.as "team.performed.edited"] `edited(
          webhookEvent(webhookPayloadTeam) => unit,
        )
      | [@bs.as "team.performed.removed_from_repository"]
        `removed_from_repository(
          webhookEvent(webhookPayloadTeam) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_team_add:
  (
    t,
    [@bs.string] [
      | [@bs.as "team_add"] `all(webhookEvent(webhookPayloadTeamAdd) => unit)
    ]
  ) =>
  unit =
  "on";

[@bs.send]
external on_watch:
  (
    t,
    [@bs.string] [
      | [@bs.as "watch"] `all(webhookEvent(webhookPayloadWatch) => unit)
      | [@bs.as "watch.started"] `started(
          webhookEvent(webhookPayloadWatch) => unit,
        )
    ]
  ) =>
  unit =
  "on";

[@bs.send] external sign: (t, 'a) => string = "";
[@bs.send] external verify: (t, 'a, string) => bool = "";
[@bs.send]
external verifyAndReceive:
  (
    t,
    {
      .
      id: string,
      name: string,
      payload: 'a,
      signature: string,
    }
  ) =>
  unit =
  "";
[@bs.send]
external receive:
  (
    t,
    {
      .
      id: string,
      name: string,
      payload: 'a,
    }
  ) =>
  unit =
  "";
[@bs.send]
external removeListener: (t, array(string), webhookEvent('a) => unit) => unit =
  "";
