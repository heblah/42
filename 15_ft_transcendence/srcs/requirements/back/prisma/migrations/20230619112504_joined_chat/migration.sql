-- CreateTable
CREATE TABLE "textChannel" (
    "id" SERIAL NOT NULL,
    "name" TEXT NOT NULL,
    "text" TEXT NOT NULL,
    "channelUserId" INTEGER NOT NULL DEFAULT -1,
    "channelId" INTEGER NOT NULL DEFAULT -1,

    CONSTRAINT "textChannel_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "block" (
    "id" SERIAL NOT NULL,
    "blockedUserId" INTEGER NOT NULL,
    "blockerUserId" INTEGER NOT NULL,
    "blockerChannelUserId" INTEGER NOT NULL DEFAULT -1,
    "blockedChannelUserId" INTEGER NOT NULL DEFAULT -1,

    CONSTRAINT "block_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "ChannelUser" (
    "id" SERIAL NOT NULL,
    "clientId" TEXT NOT NULL,
    "Name" TEXT NOT NULL DEFAULT 'unknown',
    "status" TEXT NOT NULL DEFAULT 'user',
    "muted" BOOLEAN NOT NULL DEFAULT false,
    "kicked" BOOLEAN NOT NULL DEFAULT false,
    "banned" BOOLEAN NOT NULL DEFAULT false,
    "muteExpiration" TIMESTAMP(3),
    "kickExpiration" TIMESTAMP(3),
    "banExpiration" TIMESTAMP(3),
    "channelId" INTEGER NOT NULL DEFAULT -1,

    CONSTRAINT "ChannelUser_pkey" PRIMARY KEY ("id")
);

-- CreateTable
CREATE TABLE "Channel" (
    "id" SERIAL NOT NULL,
    "status" TEXT NOT NULL DEFAULT 'public',
    "ChannelName" TEXT NOT NULL,
    "password" TEXT NOT NULL DEFAULT '',

    CONSTRAINT "Channel_pkey" PRIMARY KEY ("id")
);

-- AddForeignKey
ALTER TABLE "textChannel" ADD CONSTRAINT "textChannel_channelUserId_fkey" FOREIGN KEY ("channelUserId") REFERENCES "ChannelUser"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "textChannel" ADD CONSTRAINT "textChannel_channelId_fkey" FOREIGN KEY ("channelId") REFERENCES "Channel"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "block" ADD CONSTRAINT "block_blockerChannelUserId_fkey" FOREIGN KEY ("blockerChannelUserId") REFERENCES "ChannelUser"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "block" ADD CONSTRAINT "block_blockedChannelUserId_fkey" FOREIGN KEY ("blockedChannelUserId") REFERENCES "ChannelUser"("id") ON DELETE RESTRICT ON UPDATE CASCADE;

-- AddForeignKey
ALTER TABLE "ChannelUser" ADD CONSTRAINT "ChannelUser_channelId_fkey" FOREIGN KEY ("channelId") REFERENCES "Channel"("id") ON DELETE RESTRICT ON UPDATE CASCADE;
